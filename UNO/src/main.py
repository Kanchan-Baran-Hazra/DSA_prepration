from fastapi import FastAPI, WebSocket, WebSocketDisconnect
from fastapi.responses import FileResponse
from collections import defaultdict
import json
from src.engine import Game,Player

app = FastAPI()


class ConnectionManager:
    def __init__(self):
        self.rooms = defaultdict(list)
        self.games={}

    async def connect(self, room_id: str, user_id:str, websocket: WebSocket):
        await websocket.accept()
        self.rooms[room_id].append(websocket)
        if self.games.get(room_id,None) ==None:
            n=Game(4)                   # create game object
            self.games[room_id]=n       # keep 4 card game for now later it may be variable length
            n.add_deck()
            n.suffle_deck()
        p1=Player(user_id)
        game=self.games.get(room_id,None)
        if game!=None:
            game.add_player(p1)
            if len(game.players)==2:
                game.give_hand()
                game.play()

    def disconnect(self, room_id: str, websocket: WebSocket):
        if room_id in self.rooms:
            if websocket in self.rooms[room_id]:
                self.rooms[room_id].remove(websocket)

            if not self.rooms[room_id]:
                del self.rooms[room_id]

    async def broadcast(self, room_id: str, message: str):
        for connection in self.rooms.get(room_id, []):
            await connection.send_text(message)


manager = ConnectionManager()


@app.get("/")
async def home():
    return FileResponse("ui/index.html")


@app.websocket("/ws/{room_id}/{user_id}")
async def websocket_endpoint(websocket: WebSocket, room_id: str,user_id:str):
    await manager.connect(room_id, user_id, websocket)

    try:
        await manager.broadcast(
            room_id,
            json.dumps({
                "type": "PLAYER_CONNECTED",
                "room_id": room_id
            })
        )

        while True:
            message = await websocket.receive_text()

            await manager.broadcast(
                room_id,
                json.dumps({
                    "type": "MESSAGE",
                    "room_id": room_id,
                    "message": message
                })
            )

    except WebSocketDisconnect:
        manager.disconnect(room_id, websocket)

        await manager.broadcast(
            room_id,
            json.dumps({
                "type": "PLAYER_DISCONNECTED",
                "room_id": room_id
            })
        )