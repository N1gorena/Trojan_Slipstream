# Game Design Document
My Game Design Document will be written in plain text.


1. I plan to have 5 things, big shock there, including a non-moving bomb that looks like a minesweeper esque air bomb, tracking missile that looks like any old missile, left->right projectile bullet thats just a small yellow circle, up<->down enemy fighter that is a simple jet fighter design in red, and a random vector cloud obstacle realized by white space.
2. The game will be played using the keyboard, with each direction arrow directly corresponding to the direction of motion the player plane will take. Mouse clicks will cause bullet fire. No other input allowed in game.
3. The score will change based on length of time played and enemies downed. Score will not decrease.
4. A simple counter of current lives will keep track of lives. Players will lose a life each time a missile, bomb, enemy bullet, or cloud hits them. They will die when all lives are gone and they are hit.
5. So the way I envision it is a "blank" screen with just the top bar that has the start and pause buttons, as well as counters for score and lives.
When the start button is pressed, the player will spawn and begin "moving" to the right. Enemies will random spawn on the right side
 and randomly fire across the screen at the player. They will fire tracking missiles or normal bullets. Bombs will also spawn randomly in the middle of the screen, they will be "immobile"
 moving only in the sense that the entire screen is flowing to the left. Clouds will also spawn randomly in middle section of the screen and be given random
 motion.  If the pause button is pressed, all enemies, projectiles and objects will freeze for the time being. Using the keyboard buttons will move the player
 within the screen, and clicking the mouse will fire player projectiles. When the game ends, everything will be cleaned from the screen and reset so a start button press restarts the game.
	______________________________________________________________________________________________
	| /_s_t_a_r_t\    /_p_a_u_s_e\             lives: x              score:x                     |
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
![alt text](http://t2.gstatic.com/images?q=tbn:ANd9GcT_9tdxTsJIx_LCRhG2hm7l5nhno9ATp8fzYZ18pn_JBIDMAdHzJSOaAg "Bomb")
![alt text](http://www.gsx.com/Portals/38080/images/cloud.gif "cloud")
![alt text](http://t0.gstatic.com/images?q=tbn:ANd9GcSWMrKKdnLKXzRC_qBGjuyr_a7it7leUmrnEqoULVs5BrtXafwk "plane")
![alt text](http://t2.gstatic.com/images?q=tbn:ANd9GcTW6ZSU3K5hqvb-TwpyuDQWZ7H7SaO-wKzlYwCPhe1wDaK0Q9x1dA "Bullet")
![alt text](http://t1.gstatic.com/images?q=tbn:ANd9GcRoUXqRkjUhhcZohaOxWrbCEQdbXK8QJPLm4xd9YKyOaZb7oh4zJw "missile")

