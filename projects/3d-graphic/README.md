# FdF - 3D Wireframe Viewer

## Description 📖

FdF (Fil de Fer, French for "Wireframe") is a 3D wireframe viewer written in C using the MiniLibX graphics library. The program visualizes terrain maps by rendering them as 3D wireframe models. Each point in the input map represents a height value, which is used to create a three-dimensional representation of the terrain.

## Features 🌟

- **Multiple Projection Types:**
  - Isometric projection (default)
  - Perspective projection
  - Side view projection

- **Interactive Controls:**
  - Pan the view using arrow keys
  - Zoom in/out (using + / - keys or mouse scroll)
  - Adjust altitude (Page Up / Page Down)
  - 3D rotation (Q/E, W/S, A/D keys)
  - Reset view (R key)
  - Switch projections (P key)

- **Color Support:**
  - Read custom colors from map files (in hexadecimal format)
  - Automatic terrain coloring based on elevation
  - Smooth color interpolation between points

## Technical Details 🔧

- **Map Format:**
  - Simple text files with space-separated values
  - Each number represents a point's height
  - Optional hexadecimal color values (e.g., `10,0xFF0000` for red)
  - Example:
    ```
    0  0  0  0
    0  1  2  0
    0  2  4  0
    0  0  0  0
    ```

- **Graphics:**
  - Uses MiniLibX library for rendering
  - Digital Differential Analyzer (DDA) algorithm for line drawing
  - Double buffering for smooth rendering

## Dependencies 📦

- MiniLibX graphics library
- X11 development libraries
- Math library

## Known Issues ⚠️

1. Graphic library (MiniLibX) must be preinstalled
2. Color artifacts may occur during rotation
3. Perspective projection has limitations with large maps
4. Map parsing issues:
   - Extra spaces at line ends can create unwanted points
   - Map width validation assumes all lines have equal length

## Building and Running 🔨

```bash
make        # Compile the project
./fdf map   # Run with a map file
```

## Controls Summary 🎮

| Key           | Action                    |
|---------------|---------------------------|
| Arrow Keys    | Move view                |
| +/-           | Zoom in/out              |
| Mouse Scroll  | Zoom in/out              |
| Page Up/Down  | Adjust altitude          |
| Q/E           | Rotate around Z axis     |
| W/S           | Rotate around X axis     |
| A/D           | Rotate around Y axis     |
| P             | Change projection type    |
| R             | Reset view               |
| ESC           | Exit program             |
