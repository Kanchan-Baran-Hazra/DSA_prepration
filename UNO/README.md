# UNO Online (FastAPI + HTML/CSS/JavaScript)

A small multiplayer UNO-style game based on your terminal implementation. The server owns the cards and validates every move. Rooms support 2–4 players and update live over WebSockets.

## Run locally

1. Install Python 3.10+.
2. Open a terminal in this folder.
3. Create and activate a virtual environment (optional but recommended).
4. Install dependencies:

   ```bash
   pip install -r requirements.txt
   ```

5. Start the server:

   ```bash
   uvicorn main:app --reload
   ```

6. Open `http://127.0.0.1:8000` in two or more browser tabs.
7. Enter a display name. The first player creates a room; share the room code with friends. Other players enter that code. The host clicks **Start Game** once at least two players have joined.

## Play

- Click a card in your hand to play it.
- Wild cards ask you to select a color.
- Click **Draw card** to draw one card, or to take the current stacked penalty.
- `+2` can be stacked with `+2` or `+4`; `+4` can be stacked with `+4`, following the house rule in the terminal game.
- Rooms are in server memory. Restarting the server clears rooms.
- This is a learning/demo implementation, not an official UNO rules engine. It omits accounts, persistence, reconnection, matchmaking, and formal UNO challenge rules.

## Play over the internet

`127.0.0.1` is only your own computer. To let friends play from different networks, deploy this FastAPI app to a host that supports persistent WebSocket connections, then share the HTTPS site URL. The browser automatically uses `wss://` when the site is served over HTTPS. For production, use a persistent room store and review disconnect/reconnect handling and deployment scaling.
