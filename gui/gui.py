#!/usr/bin/env python3

from time import sleep
import os
from solver import solve, valid
from copy import deepcopy
os.environ['PYGAME_HIDE_SUPPORT_PROMPT'] = "hide"
import pygame
import sys
board = [
        [7,8,0,4,0,0,1,2,0],
        [6,0,0,0,7,5,0,0,9],
        [0,0,0,6,0,1,0,7,8],
        [0,0,7,0,4,0,2,6,0],
        [0,0,1,0,5,0,9,3,0],
        [9,0,4,0,6,0,0,0,5],
        [0,7,0,3,0,0,0,1,2],
        [1,2,0,0,0,7,4,0,0],
        [0,4,9,2,0,6,0,0,7]
        ]



answer = deepcopy(board)
solve(answer)


pygame.init()

class Sudoku:
    def __init__(self, board, width, height):
        self.bo = board
        self.size = len(board)
        self.width = width
        self.height = height
        self.rows = 9
        self.cols = 9
        self.selected = None
        self.key = None

    def draw_board(self, win):
        gap = self.width / 9
        for i in range(self.rows+1):
            if i % 3 == 0 and i != 0:
                thick = 4
            else:
                thick = 1
            pygame.draw.line(win, (0,0,0), (0, i*gap), (self.width, i*gap), thick)
            pygame.draw.line(win, (0, 0, 0), (i * gap, 0), (i * gap, self.height), thick)

        fnt = pygame.font.SysFont('comicsans', 40)

        for i in range(9):
            for j in range(9):
                if self.bo[i][j] == 0:
                    continue
                else:
                    txt = fnt.render(str(self.bo[i][j]), 1, (0, 0, 0))
                    win.blit(txt, (j*gap + (gap/2 - txt.get_width()/2), i*gap + (gap/2 - txt.get_height()/2)))




    def clicked(self, win, pos):
        sudo = self.bo
        gap = self.width / 9
        row = pos[1] // gap
        col = pos[0] // gap

#        if(sudo.selected != None):
#            pygame.draw.rect(win, (0, 0, 0), self.selected, 3)
#
        win.fill([255, 255, 255])
        self.draw_board(win)
        pygame.draw.rect(win, (255, 0, 0), ((pos[0] // gap) * gap, (pos[1] //gap) * gap, gap, gap), 3)
        self.selected = ((pos[0] // gap) * gap, (pos[1] //gap) * gap, gap, gap)
        return (row, col)

    def selection(self, loc, win):
        row = int(loc[0])
        col = int(loc[1])
        
        if self.bo[row][col] != 0:
            pass
        else:
            if(answer[row][col] == self.key):
                print('Correct')
                self.bo[row][col] = self.key
                win.fill([255, 255, 255])
                self.draw_board(win)
            else:
                print('Wrong')



def main():
    A = Sudoku(board, 540, 540)
    screen = pygame.display.set_mode((540, 540))
    screen.fill([255, 255, 255])
    running = True
    A.draw_board(screen)

    while running:
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                running = False
                pygame.quit()
            
            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_1:
                    A.key = 1
                if event.key == pygame.K_2:
                    A.key = 2
                if event.key == pygame.K_3:
                    A.key = 3
                if event.key == pygame.K_4:
                    A.key = 4
                if event.key == pygame.K_5:
                    A.key = 5
                if event.key == pygame.K_6:
                    A.key = 6
                if event.key == pygame.K_7:
                    A.key = 7
                if event.key == pygame.K_8:
                    A.key = 8
                if event.key == pygame.K_9:
                    A.key = 9

                if event.key == pygame.K_SPACE:
                    A.bo = answer
                    screen.fill([255, 255, 255])
                    A.draw_board(screen)
                    pygame.display.flip()
                    running = False
                    sleep(5)
                    pygame.quit()
                    sys.exit()
#
            if event.type == pygame.MOUSEBUTTONDOWN:
                pos = pygame.mouse.get_pos()
                loc = A.clicked(screen, pos)
                A.selection(loc, screen)



        pygame.display.update()


    sys.exit()


main()
