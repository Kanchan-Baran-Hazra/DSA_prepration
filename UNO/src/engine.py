import random


class Card:
    def __init__(self, face: str = ""):
        self.face=face
        self.number = None
        self.color = None
        self.get_card_info()

    def __str__(self):
        return f'{self.color} -- {self.number}'

    def get_card_info(self):
        parts=self.face.split("_",1)

        if(len(parts)==2):
            self.color=parts[0]
            self.number=parts[1]

        else:
            self.color=None
            self.number=parts[0]


class Player:
    def __init__(self, id):
        self.id = id
        self.hand = []
        self.nextp = None
        self.prevp = None

    def get_hand(self):
        return [i for i in self.hand]

    def is_playble(self,played_card,top_card,add_plus_card):
        print(f"== DEBUG: === PLAYER: {self.id} == CARD: {played_card} == TOP: {top_card} == PANALTY: {add_plus_card} ==")
        if add_plus_card!=0:
            if top_card.number=="+2" and (played_card.number=="+2" or played_card.number=="+4"):
                return True
            elif top_card.number=="+4" and played_card.number=="+4":
                return True
            else:
                return False
            
        played_color,played_val=played_card.color,played_card.number
        if top_card==None or played_val in ["COLOR","+4"]:
            return True
        top_color,top_value=top_card.color,top_card.number

        if played_color==top_color or played_val==top_value:
            return True

        return False

    def add_card(self,plus_card,discard_pile):
        for _ in range(plus_card):
            self.hand.append(discard_pile.pop())
        return

    def play(self,top_card,discard_pile,add_plus_card):
        if add_plus_card!=0:
            card_info=[]
            for i in self.hand:
                card_info.append(i.number)
            if top_card.number not in card_info and "+4" not in card_info:
                self.add_card(add_plus_card,discard_pile)
                return "DRAW_PANALTY"

        print("\nFor take card press 0.")  
        for i in self.hand:
            print(i,"\t")
        while(True):
            i=int(input("Enter the index of the card:"))
            if i==0:
                if add_plus_card!=0:
                    self.add_card(add_plus_card,discard_pile)
                    return "DRAW_PANALTY"

                card=discard_pile.pop()
                if self.is_playble(card,top_card,add_plus_card):
                    print(f'Card is: {card}\n 1. To keep the card press 0,\n 2.To give the card press 1.')
                    i=input("\nEnter choice:")
                    if i=='0':
                        self.hand.append(card)
                        return None
                    elif i=='1':
                        return card
                    else:
                        print("Invalid choice.!")
                else:
                    self.hand.append(card)
                    return None
            if(i>=1 and i<=len(self.hand)):
                card=self.hand.pop(i-1)

                if not self.is_playble(card,top_card,add_plus_card):
                    self.hand.append(card)
                    continue
                return card
            else:
                print("Invalid..!")


class Game:
    def __init__(self, game_of: int = 8):  # game_of 8 cards.
        self.id = 1
        self.players = []
        self.deck = []
        self.discard_pile = []

        self.card_colors = ["RED", "BLUE", "GREEN", "YELLOW"]
        self.values = list(range(1, 10))

        self.game_of = game_of  # game_of 8 cards.
        self.direction = True  # direction of play card. 0->right  1->left
        self.turn = None    # pointing to the current player
        self.head = None    # pointing to the start player
        self.tail = None    # pointing to the last player

        self.top_card=None
        self.add_plus_card=0    # when give +2 or +4

    def add_deck(self):  # create deck
        cards = []
        for _ in range(2):
            cards.append("+4")

        for i in range(4):
            cards.append(f"{self.card_colors[i]}_+2")

        for i in range(4):
            cards.append(f"{self.card_colors[i]}_SKIP")

        for i in range(4):
            cards.append(f"{self.card_colors[i]}_REVERSE")

        for _ in range(2):
            cards.append("COLOR")

        for i in self.card_colors:
            for j in self.values:
                cards.append(i + f"_{j}")

        cards += cards
        for i in cards:
            card=Card(i)
            self.deck.append(card)

    def suffle_deck(self):  # suffle all card
        random.shuffle(self.deck)

    def printf(self):
        for i in self.deck:
            print(i)
        print(len(self.deck))

    def add_player(self, player):
        if len(self.players) == 4:
            return "room full"
        self.players.append(player)

        if self.turn == None:
            self.turn = player
            self.head = player
        else:
            self.turn.nextp = player
            player.prevp = self.turn
            self.turn = self.turn.nextp

            self.turn.nextp = self.head
            self.head.prevp = self.turn
            self.tail = self.turn

        # if len(self.players) == 4:
        #     self.turn.nextp = self.head
        #     self.head.prevp = self.turn
        #     self.tail = self.turn
        #     self.turn = self.head

    def give_hand(self):
        for _ in range(self.game_of):
            for player in self.players:
                card = self.deck.pop()
                player.hand.append(card)

        for i in self.deck:
            self.discard_pile.append(i)
        for i in range(1,len(self.discard_pile)):
            if self.discard_pile[i].number in ("1","2","3","4","5","6","7","8","9"):
                self.top_card=self.discard_pile.pop(i)
                break

    def select_color(self,card):
        print("1. For RED enter 1.\n2. For GREEN enter 2\n3. For BLUE enter 3\n4. For YELLOW enter 4")
        while True:
            i=input("Enter:")
            if i=='1':
                card.color='RED'
                break
            elif i=='2':
                card.color='GREEN'
                break
            elif i=='3':
                card.color='BLUE'
                break
            elif i=='4':
                card.color='YELLOW'
                break
            else:
                print("Wrong choice.!")
        return

    def next_turn(self):
        if self.direction:
            self.turn=self.turn.nextp
        else:
            self.turn=self.turn.prevp

    def play(self):
        while True:
            print(f"=== TURN OF === {self.turn.id} === play of {self.top_card.color if self.top_card!=None else "Any"}=={self.top_card.number if self.top_card!=None else "Any"}")
            card=self.turn.play(self.top_card,self.discard_pile,self.add_plus_card)
            if card=="DRAW_PANALTY":
                self.add_plus_card=0
                self.next_turn()
                continue
            if card!=None:
                if card.number=="SKIP":
                    self.next_turn()
                elif card.number=="REVERSE":
                    self.direction=not self.direction
                elif card.number=="COLOR":
                    self.select_color(card)    
                elif card.number =="+2":
                    self.add_plus_card+=2
                elif card.number=="+4":
                    self.add_plus_card+=4
                    self.select_color(card)
                self.top_card=card
            if len(self.turn.hand)==0:
                print(f'WINER:{self.turn}')
                break
            self.next_turn()



if __name__ == "__main__":
    n = Game(4)      # game of n card
    n.add_deck()
    n.suffle_deck()
    # n.printf()
    p1=Player(1)
    p2=Player(2)
    p3=Player(3)

    n.add_player(p1)
    n.add_player(p2)
    n.add_player(p3)

    n.give_hand()

    # print(p1.get_hand())
    # print(p2.get_hand())
    # p1.play()
    n.play()


