# Cub3D
![norminette](https://github.com/Eduard953/Cub3D/workflows/Norm-Check/badge.svg) ![build](https://github.com/Eduard953/Cub3D/workflows/Build/badge.svg)

## Requirements:

#### Linux:
```bash
sudo apt update && sudo apt install xorg libxext-dev zlib1g-dev libbsd-dev
```
#### MacOS:
```bash
brew install Xquartz
reboot
```
#### School IMacs:
- Go to 'Managed Software Center'
- Search for 'Xquartz'
- Install 'Xquartz'
- Reboot the IMac (or at least click on the Button and log in again)


## Todo:

- [X] Window handling must remain smooth
- [X] Display different wall textures based on which side the wall is facing
- [X] Different colors for Floor and Ceiling
- [X] Left and Right arrow keys for turning left and right
- [X] W, A, S, D to move the Player
- [X] Esc must close the Window
- [X] Red Cross on window frame must close the Window
- [X] Map can have 0, 1, N, S, E, W characters
- [X] Map must be surrounded by walls
- [X] Apart from the map the other information can be in arbitrary order
- [X] Map can have Spaces and non-rectangular shapes
- [X] Information preceded by their Identifier (NO, SO, WE, EA, F, C) and followed by the value
- [X] If there is any error in the file display Error and a newline followed by an explicit error message
- [X] BONUS: Wall collisions
- [X] BONUS: Minimap
- [X] BONUS: Doors which can open and close
- [ ] BONUS: animated sprite
- [X] BONUS: Rotate POV with Mouse

## Folder Structure:
- `source/`: C Source Files (.c) and Private Header files (.h) sorted in subfolders
- `libraries/`: Libraries (e.g. libft, minilibx)
- `build/`: Folder for Object Files (.o) created by Makefile at buildtime
- `data/`: External Data (e.g. Images)
- `examples/`: Example Files (e.g. Example Maps)
- `tests/`: Test Files
