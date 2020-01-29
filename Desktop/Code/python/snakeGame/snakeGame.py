
from random import randint
import tkinter as tk
from PIL import Image, ImageTk

#
# Constant values
#
MOVE_INCR = 20
MOVES_PER_SEC = 15
GAME_SPEED = 1000 // MOVES_PER_SEC

#
# class for snake object to instantiate game
#
class Snake(tk.Canvas):
	def __init__(self):
		super().__init__(width=600, height=620, background="black", highlightthickness=0)

		#
		# initiate values when snake object is called
		#
		self.snake_pos = [(100,100), (80,100), (60,100)]	# starting position of snake blocks
		self.food_pos = self.set_new_food_pos()							# starting position of "food" block
		self.score = 0										# start score value to 0
		self.direction = "Right"							# start moving character to right
		self.bind_all("<Key>",self.on_key_press)			# read inputs of key values

		self.load_assets()									# load images of snake/food
		self.create_objects()								# create images into game/GUI


		self.after(GAME_SPEED,self.perform_actions)

	def load_assets(self):
		try:
			self.snake_body_image = Image.open("snake.png")
			self.snake_body = ImageTk.PhotoImage(self.snake_body_image)

			self.food_image = Image.open("food.png")
			self.food = ImageTk.PhotoImage(self.food_image)
		except IOError as error:
			print(error)
			root.destroy()

	def create_objects(self):
		self.create_text(
			45,12,text=f"Score {self.score}", tag="score", fill="#fff",font=("TkDefaultFont",14)
			)
		for x_pos, y_pos in self.snake_pos:
			self.create_image(x_pos,y_pos, image=self.snake_body, tag="snake")

		self.create_image(*self.food_pos, image=self.food, tag="food")
		self.create_rectangle(7,27,593,613,outline="#525d69")

	def move_snake(self):
		head_x_pos, head_y_pos = self.snake_pos[0] #destructure
		
		#movement reading input from key input
		if self.direction == "Left":
			new_head_pos = (head_x_pos - MOVE_INCR, head_y_pos)
		elif self.direction == "Right":
			new_head_pos = (head_x_pos + MOVE_INCR, head_y_pos)
		elif self.direction == "Up":
			new_head_pos = (head_x_pos, head_y_pos - MOVE_INCR)
		elif self.direction == "Down":
			new_head_pos = (head_x_pos, head_y_pos + MOVE_INCR)


		self.snake_pos = [new_head_pos] + self.snake_pos[:-1]

		for segment, pos in zip(self.find_withtag("snake"),self.snake_pos):
			self.coords(segment,pos)
	#called every 65ms, moves snake, reads key input, and checks if snake collides
	def perform_actions(self):
		if self.check_collisions():
			return
		self.check_food_collision()
		self.move_snake()
		self.after(GAME_SPEED, self.perform_actions)
	#check if snake hits itself or walls/
	def check_collisions(self):
		head_x_pos, head_y_pos = self.snake_pos[0]
		return (
			head_x_pos in (0,600)
			or head_y_pos in (20,620)
			or (head_x_pos,head_y_pos) in self.snake_pos[1:]
		)
	#read keyboard values
	def on_key_press(self, e):
		new_direction = e.keysym
		all_directions = ("Up", "Down", "Left", "Right")
		opposites = ({"Up","Down"}, {"Left","Right"})
		if (new_direction in all_directions
			and {new_direction, self.direction} not in opposites
		):
			self.direction = new_direction

	def check_food_collision(self):
		if self.snake_pos[0] == self.food_pos:
			self.score += 1
			self.snake_pos.append(self.snake_pos[-1])
			self.create_image(
				*self.snake_pos[-1], image=self.snake_body, tag="snake")

			self.food_pos = self.set_new_food_pos()
			self.coords(self.find_withtag("food"),self.food_pos)

			score = self.find_withtag("score")
			self.itemconfigure(score, text=f"Score: {self.score}", tag="score")
	def set_new_food_pos(self):
		while True:
			x_pos = randint(1,29) * MOVE_INCR
			y_pos = randint(3,30) * MOVE_INCR
			food_pos = (x_pos,y_pos)

			if food_pos not in self.snake_pos:
				return food_pos

#end of Snake Class

#
# create GUI object to call to start game
#
root = tk.Tk() #creates main window
root.title("Snake Game")
root.resizable(False,False) #users cannot resize game


board = Snake()
board.pack() #load the game

root.mainloop() #starts the app/GUI


