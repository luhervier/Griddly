BWDistantResources32x32
=======================

Description
-------------

No Description

Objects
-------

.. list-table:: Tiles
   :header-rows: 2

   * - Name ->
     - minerals
     - fixed_wall
     - harvester
     - base
   * - Map Char ->
     - M
     - W
     - H
     - B
   * - SPRITE_2D
     - .. image:: img/BWDistantResources32x32-object-SPRITE_2D-minerals.png
     - .. image:: img/BWDistantResources32x32-object-SPRITE_2D-fixed_wall.png
     - .. image:: img/BWDistantResources32x32-object-SPRITE_2D-harvester.png
     - .. image:: img/BWDistantResources32x32-object-SPRITE_2D-base.png
   * - BLOCK_2D
     - .. image:: img/BWDistantResources32x32-object-BLOCK_2D-minerals.png
     - .. image:: img/BWDistantResources32x32-object-BLOCK_2D-fixed_wall.png
     - .. image:: img/BWDistantResources32x32-object-BLOCK_2D-harvester.png
     - .. image:: img/BWDistantResources32x32-object-BLOCK_2D-base.png


Levels
---------

.. list-table:: Levels
   :header-rows: 1

   * - 
     - SPRITE_2D
     - BLOCK_2D
   * - 0
     - .. thumbnail:: img/BWDistantResources32x32-level-SPRITE_2D-0.png
     - .. thumbnail:: img/BWDistantResources32x32-level-BLOCK_2D-0.png

YAML
----

.. code-block:: YAML

   Version: "0.1"
   Environment:
     Name: BWDistantResources32x32
     TileSize: 16
     BackgroundTile: oryx/oryx_tiny_galaxy/tg_sliced/tg_world/tg_world_floor_panel_metal_a.png
     Player:
       Count: 2
     Termination:
       Lose:
         - eq: [base:count, 0] # If the player has no bases
       Win:
         - eq: [_score, 10] # First player to 10 reward points
     Levels:
       - |
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  M  M  M 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  M  M 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  M 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  H1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  B1 .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  W  W  W  W  W  .  .  .  . 
         .  .  .  .  W  W  W  W  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  B2 .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  H2 .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         .  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .
         M  .  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         M  M  .  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  . 
         M  M  M  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .  .

   Actions:
     - Name: gather
       Behaviours:
         - Src:
             Object: harvester
             Commands:
               - incr: resources
               - reward: 1
           Dst:
             Object: minerals
             Commands:
               - decr: resources
         - Src:
             Object: harvester
             Commands:
               - decr: resources
               - reward: 1
           Dst:
             Object: base
             Commands:
               - incr: resources

     - Name: move
       Behaviours:
         - Src: 
             Object: [harvester]
             Commands:
               - mov: _dest # mov will move the object, _dest is the destination location of the action
           Dst:
             Object: _empty

   Objects:
     - Name: minerals
       MapCharacter: M
       Variables:
         - Name: resources
           InitialValue: 10
       Observers:
         Sprite2D:
           Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_items/tg_items_crystal_green.png
         Block2D:
           Shape: triangle
           Color: [0.0, 1.0, 0.0]
           Scale: 1.0

     - Name: fixed_wall
       MapCharacter: W
       Observers:
         Sprite2D:
           TilingMode: WALL_2 # Will tile walls with two images
           Image:
             - oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img33.png
             - oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img40.png
         Block2D:
           Color: [0.5, 0.5, 0.5]
           Shape: square

     - Name: harvester
       MapCharacter: H
       Variables:
         - Name: resources
           InitialValue: 0
         - Name: health
           InitialValue: 10
       Observers:
         Sprite2D:
           Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_monsters/tg_monsters_jelly_d1.png
         Block2D:
           Shape: square
           Color: [0.6, 0.2, 0.2]
           Scale: 0.5

     - Name: base
       MapCharacter: B
       Variables:
         - Name: resources
           InitialValue: 0
         - Name: health
           InitialValue: 10
       Observers:
         Sprite2D:
           Image: oryx/oryx_tiny_galaxy/tg_sliced/tg_world_fixed/img324.png
         Block2D:
           Color: [0.8, 0.8, 0.3]
           Shape: triangle

