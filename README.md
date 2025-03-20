# 📌 so_long

## 📝 Description
**so_long** is a simple 2D game written in **C**, using the **MiniLibX** graphical library. The goal is to implement a basic game where the player moves through a map, collecting items and reaching the exit while avoiding obstacles. The project focuses on understanding event handling, graphics rendering, and memory management.

## 🔄 Map Parsing
To correctly parse the map and the `.ber` file, follow these steps:

1. **Read the Map File**: Open and read the `.ber` file, ensuring it follows the correct format.
2. **Validate the Map**:
   - Ensure all rows have the same length.
   - Check that the map is surrounded by walls (`1` characters).
   - Ensure there is at least **one player (`P`), one exit (`E`), and one collectible (`C`)**.
3. **Store the Map Data**:
   - Convert the file content into a **2D array** for easy processing.
4. **Render the Map**:
   - Load assets and display the game grid with appropriate textures for walls, floor, collectibles, player, and exit.

## 🎮 Controls
The game accepts the following controls for movement:

| Key  | Action        |
|------|--------------|
| `W`  | Move Up      |
| `A`  | Move Left    |
| `S`  | Move Down    |
| `D`  | Move Right   |
| `ESC`| Close Game   |

Additionally, the **ESC key** should correctly exit the game, freeing all allocated memory.

## 🏃 Character Movement
- The player **moves smoothly** by updating pixel positions in the game window.
- Movements are triggered via keyboard inputs (`WASD`).
- Collision detection ensures the player cannot walk through walls.

## 🛠️ Memory Management
To prevent **memory leaks**, ensure proper deallocation in these scenarios:

✔ **When the game ends normally**
✔ **When the player presses ESC**
✔ **When the player clicks the close window button (cross icon)**

🚨 **It is expected that the game will cause a memory leak when interrupted using** `CTRL+C` **(this is intentional behavior).**

## 🎨 Game Assets
| Asset Type  | File Path |
|------------|-----------|
| Player_Right     | ![Image](https://github.com/user-attachments/assets/f438095f-25f3-4076-8c4f-76a41a25f93b) |
| Player_Left     | ![Image](https://github.com/user-attachments/assets/45fda2dd-420e-44ef-b252-d68036f96cf0) |
| Collectible | ![Image](https://github.com/user-attachments/assets/ed2da34b-9b2e-4cba-8eee-59229cbd20c1) |
| Wall       | ![Image](https://github.com/user-attachments/assets/6e953b1e-46df-41a0-98d9-209c62d35f37) |
| Floor      | ![Image](https://github.com/user-attachments/assets/3ba3aad0-eff6-44c4-b05a-f7a139aca843)|
| Exit       | ![Image](https://github.com/user-attachments/assets/a8237abd-fba1-463d-940e-767cda58cb38) |
| Exit1       | ![Image](https://github.com/user-attachments/assets/5718d754-9134-430f-b446-1388335da071) |


![Image](https://github.com/user-attachments/assets/f438095f-25f3-4076-8c4f-76a41a25f93b)

![Image](https://github.com/user-attachments/assets/45fda2dd-420e-44ef-b252-d68036f96cf0)

![Image](https://github.com/user-attachments/assets/ed2da34b-9b2e-4cba-8eee-59229cbd20c1)

![Image](https://github.com/user-attachments/assets/6e953b1e-46df-41a0-98d9-209c62d35f37)

![Image](https://github.com/user-attachments/assets/3ba3aad0-eff6-44c4-b05a-f7a139aca843)

![Image](https://github.com/user-attachments/assets/a8237abd-fba1-463d-940e-767cda58cb38)

![Image](https://github.com/user-attachments/assets/5718d754-9134-430f-b446-1388335da071)

## 🎥 Gameplay GIF
[Click here to view the game in action](#) *(Replace with the actual GIF link when available).*

