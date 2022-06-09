# Pong_clone
## Space Pong

This is a Pong clone based on the Tutorial "Game From Scratch C++ and SFML Edition!" ( https://gamefromscratch.com/game-from-scratch-c-and-sfml-edition/ )
I started this project to freshen up and expand my knowledge on C++ and SFML.
Also I updated the code for SFML 2.5.1 and VS 2019.
The Textures are created and edited with Inkscape.

##  [Release v1.00](https://github.com/Nicky-Git/Pong_clone/releases/tag/v1.00)

This is the first release of the final game.  
The code from the tutoral got updated quite a bit.  
The main changes are:  
- A 2 Player mode was added.
- The 1 Player mode v. the NPC war improved.
- A Winscreem was added.
- A Pause menu was added.
- multiple bugs were resolved.
- the code was updated for SFML 2.5.1 and VS 2019.
- a score counter was added.


Also the biggest bug of the original tutorial concerning the updating of the elements was resolved,
 by deviding the main loop into a game loop , an update loop and a render loop.
 Aditionally a pause game option was added including a pause menu, having a simple overview of the game controlls.

```cpp
while (!IsExiting()) {
	GameLoop();
	if (!Pause()) {
		GameUpdate(TimePerFrame_sec);
	}
    render();
}
```
The Game is tested for windows and Linux.
### For the use on Windows

 [Release v1.00](https://github.com/Nicky-Git/Pong_clone/releases/tag/v1.00)  

Download the .zip file of the release, Unpack to a dseired folder and RUN the .exe file.
Everything should work out of the box.

### For the use on Linux

 [Release v1.00](https://github.com/Nicky-Git/Pong_clone/releases/tag/v1.00)  

Download the .zip file of the release, Unpack to a dseired folder and RUN the .exe file.
In order to run the .exe file on Linux only Wine is needed.
For further information on WINE see https://www.winehq.org/.

Everything else should work out of the box.
