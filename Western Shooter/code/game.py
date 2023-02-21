# library imports
import pygame
import sys
from pytmx.util_pygame import load_pygame

# local imports
from settings import *
from player import Player
from allsprites import AllSprites
from sprite import Sprite

class Game:
	def __init__(self):
		pygame.init()
		self.display_surface = pygame.display.set_mode((WINDOW_WIDTH, WINDOW_HEIGHT))
		pygame.display.set_caption('Western shooter')
		self.clock = pygame.time.Clock()

		# groups
		self.all_sprites = AllSprites()
		self.obstacles = pygame.sprite.Group()

		self.setup()

	def setup(self):

		tmx_map = load_pygame('../data/map.tmx')

		# tiles
		for x, y, surf in tmx_map.get_layer_by_name('Fence').tiles():
			Sprite((x * 64, y * 64),surf,[self.all_sprites, self.obstacles])

		# objects
		for obj in tmx_map.get_layer_by_name('Objects'):
			Sprite((obj.x, obj.y),obj.image,[self.all_sprites, self.obstacles])

		# entities
		for obj in tmx_map.get_layer_by_name('Entities'):
			if obj.name == 'Player':
				self.player = Player((obj.x,obj.y), self.all_sprites, PATHS['player'], self.obstacles)

	def run(self):
		while True:
			# event loop 
			for event in pygame.event.get():
				if event.type == pygame.QUIT:
					pygame.quit()
					sys.exit()
			dt = self.clock.tick() / 1000

			# update groups 
			self.all_sprites.update(dt)

			# draw groups
			self.all_sprites.customize_draw(self.player)

			pygame.display.update()


# execute Game
if __name__ == '__main__':
	Game().run()