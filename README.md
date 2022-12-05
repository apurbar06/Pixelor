# Pixelor

>This C++ program creates a pixelated version of an image.
>It basically takes the average color of an area around a pixel and then fill the area with the said color.

<img src="https://user-images.githubusercontent.com/55590340/205624544-f7c1c138-e62b-4313-84c6-43f7dfd03057.png" width=80% height=70%>
<img src="https://user-images.githubusercontent.com/55590340/205624568-9690dda0-6c4d-4b09-aeca-877facbea5b0.png" width=40% height=40%>


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
