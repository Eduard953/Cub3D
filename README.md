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

1. input validation

2. initiate the game

3. build the game

4. finish the game

5. handle errors, norm & leaks

## Folder Structure:
- `source/`: C Source Files (.c) and Private Header files (.h) sorted in subfolders
- `include/`: Public-Facing Header Files (.h) with subfolders
- `libraries/`: Libraries (e.g. libft, minilibx)
- `build/`: Folder for Object Files (.o) created by Makefile at buildtime
- `data/`: External Data (e.g. Images)
- `examples/`: Example Files (e.g. Example Maps)
- `tests/`: Test Files
