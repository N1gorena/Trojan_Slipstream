# Game Design Document
My Game Design Document will be written in plain text.


1. I plan to have 5 things, big shock there, including a non-moving bomb that looks like a minesweeper esque air bomb, tracking missile that looks like any old missile, left->right projectile bullet thats just a small yellow dashes, up<->down enemy fighter that is a simple jet fighter design in red, and a random vector cloud obstacle realized by thunder cloud.
2. The game will be played using the keyboard, with w (up) a (left) s (down) d (right) and q(up/left) e(up/right) z(down/left) c(down/right)  keys directly corresponding to the direction of motion the player plane will take. No other input allowed to control player in game.
3. The score will change based on length of time played. Score will not decrease.
4. A simple health bar will keep track of health/lives. Players will lose health/a life each time a missile, bomb, enemy bullet, or cloud hits them. They will die when all lives are gone and they are hit.
5. So the way I envision it is a "blank" screen with just the top bar that has the start and pause buttons, as well as counters for score and lives.
When the start button is pressed, the player will spawn with an Enemy and a cloud already present, to introduce them with no danger of the player being hit should they not move into anything straight away.
The enemy will randomly fire across the screen at the player. They will fire tracking missiles or normal bullets. Bombs will also spawn near or around the middle of the screen, though they can spread around. 
A cloud will also spawn in the middle section of the screen and move randomly given an initial trajectory.
  If the pause button is pressed, all enemies, projectiles and objects will freeze for the time being. Using the keyboard buttons will move the player
 within the screen. When the game ends, everything will be paused, hitting start will clean the screen and reset the game as it would normally.
 
 
 To clarify: The bomb is a static object whereas the cloud is a moving one. 
 The cloud moves slowly(its a cloud) around the screen with a random vector given upon spawning.
	______________________________________________________________________________________________
	| /_s_t_a_r_t\    /_p_a_u_s_e\  /Q_u_i_t\      score:x         |||||  |(hp bar)              |
	|--------------------------------------------------------------------------------------------|
	|                                                                                            |
	|				bomb:                                            enemy:      |
	|				 _			        -------           /--|	     |
	|				|x|                           en fire:          <----|       |
	|				---				-------           \--|	     |
	|						                                             |
	|                                                                                            |
	|                                    missile:   ___					     |
	|					      <[___|					     |
	|      Player:										     |
	|	|--\             p fire:                                                             |										             |
	|	|---->		--------							     |
	|	|--/										     |
	|											     |
	|											     |
	|											     |
	|					  ______					     |
	|					 /	\					     |
	|					/	 \					     |
	|				        | cloud	 |					     |
	|					\	/					     |
	|					 \_____/					     |
	|											     |
	----------------------------------------------------------------------------------------------

Images are added inline by using the following syntax
+ [Bomb](images/mine.png)
+ [Player Jet](images/playerjet.png)
+ [Enemy Jet](images/ejet.png)
+ [Cloud](images/cloud.png)
+ [background](images/background.jpg)
+ [missile](images/missile.jpg)
+ [bullet](images/bullet.png)
![alt text](http://www.gsx.com/Portals/38080/images/cloud.gif "cloud")
![alt text](http://t0.gstatic.com/images?q=tbn:ANd9GcSWMrKKdnLKXzRC_qBGjuyr_a7it7leUmrnEqoULVs5BrtXafwk "plane")
![alt text](http://t2.gstatic.com/images?q=tbn:ANd9GcTW6ZSU3K5hqvb-TwpyuDQWZ7H7SaO-wKzlYwCPhe1wDaK0Q9x1dA "Bullet")
![alt text](http://t1.gstatic.com/images?q=tbn:ANd9GcRoUXqRkjUhhcZohaOxWrbCEQdbXK8QJPLm4xd9YKyOaZb7oh4zJw "missile")

![backround](http://t3.gstatic.com/images?q=tbn:ANd9GcSEZ8RvcQLURtRQBWMvtjgKZyM5WR7wZu8RVpuh6Bny3WrGeCmyaQ "background")

