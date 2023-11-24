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

Trivial change: We plan to rename Game class to Level class as it is more suitable according to the content.


## Meeting 22.11.2023
 All members participated in Achitecture and UML planning.
 - Leevi created map selector renderer, enemy path renderer and game loop skeleton. He also participated in bug fixing.
 - Aleksi was working on game loop, tower placement, bug fixing and overall improved the GUI of the application.
 - Imran was working on classes and their method implementations and fixed bugs.

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



