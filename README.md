# Pixelor

>This C++ program creates a pixelated version of an image.
>It basically takes the average color of an area around a pixel and then fill the area with the said color.

## Building

Requires the SFML library

On Ubuntu:

```sh
sudo apt-get install libsfml-dev
cmake <path-to-source>
make
```

On OSX with [Homebrew](https://brew.sh/):
```sh
brew install sfml
cmake <path-to-source>
make
```

## Run
```sh
./Pixelor <path-to-image> <pixel-size>
```
Note: Both the width and the height of the image must be divisible by the pixel-size
