# Meeting Notes

In this file, you are required to take notes for your weekly meetings.
In each meeting, you are required to discuss:

1. What each member has done during the week?
2. Are there challenges or problems? Discuss the possible solutions
3. Plan for the next week for everyone
4. Deviations and changes to the project plan, if any

## Meeting 15.11.2023

### To do list:

- Update the Kanban
- Divide the tasks

Currently we have the last skeletons written in code that we made in the YML. We just changed from SDL2 to SMFL. We've been already drawing some map formats. The json isn't fully written yet. The next step, we need to connect the json into the grid class. We are a bit behind schedule.

Game class is in progress by Aleksi.

- Leevi is currently adding the code to load map and render the level background
- Valerie is doing main menu and level selection.
- Valerie add music theme.
- Imran is working on implementing methods for the Tower class and its subclasses.
  Additionally, added the toolbar.

Trivial change: We plan to rename Game class to Level class as it is more suitable according to the content.


## Meeting 22.11.2023
 All members participated in Achitecture and UML planning.
 - Leevi created map selector renderer, enemy path renderer and game loop skeleton. He also participated in bug fixing.
 - Aleksi was working on game loop, tower placement, bug fixing and overall improved the GUI of the application.
 - Imran was working on classes and their method implementations. Additionally fixed bugs and warnings.

 ## 23.11.2023 - 24.11.2023
 I (Leevi) made a branch called leesalon/feature/path-deduction-features-and-more-painting-stuff. Currently already merged to master.

 This branch contained following updates in short (more on these updates can be found from the commits):
 - Changed the names of all the tiles to logical ordering that is based on the original tile layout. When making a map editor the layout can rendered as it was intended.
 - Add new class TextureManager. It loads all the textures from rsrc/tiles and its subdirectories. Its purpose is to avoid loading duplicate textures.
 - Update the test map.
 - Add a setter function to the (tile) interface.
 - Add enemy path deduction to the GameGrid constructor.
 - Add functionality to check whether the tile where placing an artillery is empty and isn't a path tile. According to this render the selection on green / red when artillery is being placed and is selected.
 - Debug: Draw light blue overlay on the enemy path tiles.


## 29-30.11.2023

-Leevi:
Added GameObjectRenderer and fixed bugs.


-Aleksi
Working on gameloop and created ToolbarRenderer(deleted for now). Modifications to various classes.


-Imran:
I (Imran) implemented update(), fire(), getEnemiesWithinRadius() and probably some other methods
in classes. I also wrote some unit tests to test functionality of the methods. I merged imran/game-logic/towers_and_enemies and fix-gameloop branches to the master. I'm planning to implement also the fire() in
Cannon class and start working on gameloop.

## 5.12.2023

- Leevi & Imran: Tinkering on the program architechture. We concluded that the enemy logic must be written to the level files itself.

- Imran: Fixed mostly, but still partially the bug around path type resolvation from the enemy path.

- Leevi:
	* Changed a lot of code in gameloop. Fixed bugs in Game class. Improved / fixed the GameObjectRenderer.
	* Fixed the bug that allows to set tiles over the path.
	* Created a json format for the enemy waves:
	```
	"enemy_waves": [
		{
			"duration_seconds": 60,
			"enemies": [
				"FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1",
				"FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1",
				"FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1",
				"FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1"
			]
		},
		{
			"duration_seconds": 120,
			"enemies": [
				"FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1",
				"FootSoldier2", "FootSoldier2", "FootSoldier2", "FootSoldier2", "FootSoldier2", "FootSoldier2",
				"Tank1",        "FootSoldier1", "FootSoldier1", "Tank1",        "FootSoldier1", "FootSoldier2",
				"FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1", "FootSoldier1",
				"Tank1",        "FootSoldier2", "Tank1",        "FootSoldier2", "Tank1",        "FootSoldier2",
				"Tank1",        "Tank1",        "Tank1",        "FootSoldier3", "FootSoldier3", "Tank2"
			]
		}
    ]
	```
	* Update the level 1 map with the information on the enemy waves.
	* Fix the path resolving bug once and for all. Add additional bounds checking into the resolving algorithm.
