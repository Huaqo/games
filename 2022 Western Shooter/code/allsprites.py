# library imports
import pygame
from pygame.math import Vector2 as vector

# local imports
from settings import *

class AllSprites(pygame.sprite.Group):
	
	def __init__(self):
		super().__init__()
		self.offset = vector()
		self.display_surface = pygame.display.get_surface()
		self.bg = pygame.image.load('../graphics/other/bg.png').convert()

	def customize_draw(self,player):

		# change the offset vector
		self.offset.x = player.rect.centerx - WINDOW_WIDTH / 2
		self.offset.y = player.rect.centery - WINDOW_HEIGHT / 2

		# blit the surfaces 
		self.display_surface.blit(self.bg,-self.offset)
		for sprite in sorted(self.sprites(), key = lambda sprite: sprite.rect.centery):
			offset_rect = sprite.image.get_rect(center = sprite.rect.center)
			offset_rect.center -= self.offset
			self.display_surface.blit(sprite.image,offset_rect)
