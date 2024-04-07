# My Sokoban
## Description :scroll:
This Sokoban is designed to be played in the terminal. I realized it in C with Ncurses during my first year at Epitech Technology. The objective of the game is to move all boxes to storage locations to win. If all boxes are on storage locations, the player wins, and the program returns 0. If none of the boxes can be moved anymore, the player loses, and the program returns 1.

## How to Play :question:
Use the arrow keys (LEFT, RIGHT, UP, and DOWN) to move the player 'P' on the map.
The game allows the player to reset by pressing the space bar.
Move the player towards the boxes 'X' to push them to storage locations 'O'.
Win the game by placing all boxes on storage locations.
## Rules and Controls :keyboard:
The game can be reset by pressing the space bar.
If an invalid map is supplied, the program exits with an error.

## Running the Game :arrow_forward:
To run the game, execute the following command in your terminal:

```./my_sokoban map```

Make sure to replace 'map' with the path to your game map file.

## Example Map :world_map:
A valid map can only contain the following characters: SPACE, ‘\n’, ‘#’, ‘X’, ‘O’, and ‘P’.
A valid map may look like this:
```
#######
#     #
# P X #
# O   #
#######
```
[#]: Wall :bricks:
[P]: Player :video_game:
[X]: Box :package:
[O]: Storage location :inbox_tray:
[SPACE]: Empty space :hole:
## Exiting the Game :door:
At the end of the game, the last turn is printed, and the program exits.

Have fun playing My Sokoban !