Drunk Dwarf
===========

Description
-------------

A port of the games provided in the https://github.com/maximecb/gym-minigrid environment, but you're a drunk dwarf trying find your keys that you've dropped to get to your bed (which is a coffin?? Wierd.).

Levels
---------

.. list-table:: Levels
   :header-rows: 1

   * - 
     - Sprite2D
     - Block2D
   * - .. list-table:: 

          * - Level ID
            - 0
          * - Size
            - 6x6
     - .. thumbnail:: img/Drunk_Dwarf-level-Sprite2D-0.png
     - .. thumbnail:: img/Drunk_Dwarf-level-Block2D-0.png
   * - .. list-table:: 

          * - Level ID
            - 1
          * - Size
            - 7x7
     - .. thumbnail:: img/Drunk_Dwarf-level-Sprite2D-1.png
     - .. thumbnail:: img/Drunk_Dwarf-level-Block2D-1.png
   * - .. list-table:: 

          * - Level ID
            - 2
          * - Size
            - 8x8
     - .. thumbnail:: img/Drunk_Dwarf-level-Sprite2D-2.png
     - .. thumbnail:: img/Drunk_Dwarf-level-Block2D-2.png
   * - .. list-table:: 

          * - Level ID
            - 3
          * - Size
            - 10x10
     - .. thumbnail:: img/Drunk_Dwarf-level-Sprite2D-3.png
     - .. thumbnail:: img/Drunk_Dwarf-level-Block2D-3.png
   * - .. list-table:: 

          * - Level ID
            - 4
          * - Size
            - 19x18
     - .. thumbnail:: img/Drunk_Dwarf-level-Sprite2D-4.png
     - .. thumbnail:: img/Drunk_Dwarf-level-Block2D-4.png

Code Example
------------

Basic
^^^^^

The most basic way to create a Griddly Gym Environment. Defaults to level 0 and SPRITE_2D rendering.

.. code-block:: python


   import gym
   import numpy as np
   import griddly

   if __name__ == '__main__':

       env = gym.make('GDY-Drunk-Dwarf-v0')
       env.reset()
    
       # Replace with your own control algorithm!
       for s in range(1000):
           obs, reward, done, info = env.step(env.action_space.sample())
           env.render()

           env.render(observer='global')


Advanced
^^^^^^^^

Create a customized Griddly Gym environment using the ``GymWrapperFactory``

.. code-block:: python


   import gym
   import numpy as np
   from griddly import GymWrapperFactory, gd

   if __name__ == '__main__':
       wrapper = GymWrapperFactory()

       wrapper.build_gym_from_yaml(
           'Drunk-Dwarf-Adv',
           'Single-Player/Mini-Grid/minigrid-drunkdwarf.yaml',
           level=0,
           global_observer_type=gd.ObserverType.SPRITE_2D,
           player_observer_type=gd.ObserverType.SPRITE_2D,
           tile_size=10
       )

       env = gym.make('GDY-Drunk-Dwarf-Adv-v0')
       env.reset()

       # Replace with your own control algorithm!
       for s in range(1000):
           obs, reward, done, info = env.step(env.action_space.sample())
           env.render()

           env.render(observer='global')


Objects
-------

.. list-table:: Tiles
   :header-rows: 2

   * - Name ->
     - wall
     - coffin_bed
     - drunk_dwarf
     - door
     - doggo
     - chair
     - table
     - bookshelf
     - key
   * - Map Char ->
     - W
     - g
     - A
     - D
     - d
     - c
     - t
     - b
     - k
   * - Sprite2D
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-wall.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-coffin_bed.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-drunk_dwarf.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-door.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-doggo.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-chair.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-table.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-bookshelf.png
     - .. image:: img/Drunk_Dwarf-object-Sprite2D-key.png
   * - Block2D
     - .. image:: img/Drunk_Dwarf-object-Block2D-wall.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-coffin_bed.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-drunk_dwarf.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-door.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-doggo.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-chair.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-table.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-bookshelf.png
     - .. image:: img/Drunk_Dwarf-object-Block2D-key.png


Actions
-------

stumble
^^^^^^^

:Relative: The actions are calculated relative to the object being controlled.

.. list-table:: 
   :header-rows: 1

   * - Action Id
     - Mapping
   * - 1
     - Rotate left
   * - 2
     - Move forwards
   * - 3
     - Rotate right


YAML
----

.. code-block:: YAML

   Version: "0.1"
   Environment:
     Name: Drunk Dwarf
     Description: A port of the games provided in the https://github.com/maximecb/gym-minigrid environment, but you're a drunk dwarf trying find your keys that you've dropped to get to your bed (which is a coffin?? Wierd.).
     Observers:
       Sprite2D:
         TileSize: 24
         BackgroundTile: oryx/oryx_fantasy/floor1-1.png
     Player:
       AvatarObject: drunk_dwarf # The player can only control a single drunk_dwarf in the game
       Observer:
         RotateWithAvatar: true
         TrackAvatar: true
         Height: 7
         Width: 7
         OffsetX: 0
         OffsetY: 3
     Termination:
       Win:
         - eq: [coffin_bed:count, 0] # If there are no boxes left
     Levels:
       - |
         W  W  W  W  W  W
         W  A  W  .  .  W
         W  .  W  .  .  W
         W  .  D  .  .  W
         W  k  W  .  g  W
         W  W  W  W  W  W
       - |
         W  W  W  W  W  W  W
         W  .  .  W  .  .  W
         W  .  k  W  .  .  W
         W  .  .  D  .  .  W
         W  A  .  W  .  .  W
         W  .  .  W  .  g  W
         W  W  W  W  W  W  W
       - |
         W  W  W  W  W  W  W  W
         W  A  .  W  .  b  .  W
         W  .  .  W  .  .  .  W
         W  .  .  D  .  .  .  W
         W  .  .  W  .  .  .  W
         W  k  .  W  .  t  .  W
         W  .  .  W  .  .  g  W
         W  W  W  W  W  W  W  W
       - |
         W  W  W  W  W  W  W  W  W  W
         W  A  .  .  W  .  .  b  b  W
         W  .  .  .  W  .  c  .  .  W
         W  .  .  .  W  .  .  .  g  W
         W  .  .  .  W  .  .  .  .  W
         W  .  .  .  D  .  .  .  .  W
         W  .  .  .  W  .  .  .  .  W
         W  .  .  .  W  .  t  t  .  W
         W  .  k  d  W  .  .  .  .  W
         W  W  W  W  W  W  W  W  W  W
       - |
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W
         W  .  .  .  .  .  W  .  .  .  .  b  b  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  c  c  c  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  D  .  .  .  .  .  g  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  k  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  t  .  .  W
         W  .  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  .  .  .  .  .  W  .  .  t  .  .  .  .  .  .  .  .  W
         W  A  .  .  .  .  W  .  .  .  .  .  .  .  .  .  .  .  W
         W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W  W

   Actions:
     # Define the move action
     - Name: stumble
       InputMapping:
         Inputs:
           1:
             Description: Rotate left
             OrientationVector: [-1, 0]
           2:
             Description: Move forwards
             OrientationVector: [0, -1]
             VectorToDest: [0, -1]
           3:
             Description: Rotate right
             OrientationVector: [1, 0]
         Relative: true
       Behaviours:
         # Tell the agent to rotate if the drunk_dwarf performs an action on itself
         - Src:
             Object: drunk_dwarf
             Commands:
               - rot: _dir
           Dst:
             Object: drunk_dwarf

         # The agent can move around freely in empty and always rotates the direction it is travelling
         - Src:
             Object: drunk_dwarf
             Commands:
               - mov: _dest
           Dst:
             Object: [_empty, open_door]

         # If the drunk_dwarf moves into a coffin_bed object, the coffin_bed is removed, triggering a win condition
         - Src:
             Object: drunk_dwarf
             Commands:
               - reward: 1
           Dst:
             Object: coffin_bed
             Commands:
               - remove: true

         # Keys and Locks
         - Src:
             Preconditions:
               - eq: [has_key, 1]
             Object: drunk_dwarf
             Commands:
               - mov: _dest
           Dst:
             Object: door
             Commands:
               - change_to: open_door
               - reward: 1

         # Avatar picks up the key
         - Src:
             Object: drunk_dwarf
             Commands:
               - mov: _dest
               - incr: has_key
               - reward: 1
           Dst:
             Object: key
             Commands:
               - remove: true

   Objects:
     - Name: wall
       MapCharacter: W
       Observers:
         Sprite2D:
           - TilingMode: WALL_16
             Image:
               - oryx/oryx_fantasy/wall1-0.png
               - oryx/oryx_fantasy/wall1-1.png
               - oryx/oryx_fantasy/wall1-2.png
               - oryx/oryx_fantasy/wall1-3.png
               - oryx/oryx_fantasy/wall1-4.png
               - oryx/oryx_fantasy/wall1-5.png
               - oryx/oryx_fantasy/wall1-6.png
               - oryx/oryx_fantasy/wall1-7.png
               - oryx/oryx_fantasy/wall1-8.png
               - oryx/oryx_fantasy/wall1-9.png
               - oryx/oryx_fantasy/wall1-10.png
               - oryx/oryx_fantasy/wall1-11.png
               - oryx/oryx_fantasy/wall1-12.png
               - oryx/oryx_fantasy/wall1-13.png
               - oryx/oryx_fantasy/wall1-14.png
               - oryx/oryx_fantasy/wall1-15.png
         Block2D:
           - Shape: square
             Color: [0.7, 0.7, 0.7]
             Scale: 1.0

     - Name: coffin_bed
       MapCharacter: g
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/coffin-1.png
         Block2D:
           - Shape: square
             Color: [0.0, 1.0, 0.0]
             Scale: 0.8

     - Name: drunk_dwarf
       MapCharacter: A
       Z: 1
       Variables:
         - Name: has_key
           InitialValue: 0
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/avatars/dwarf1.png
         Block2D:
           - Shape: triangle
             Color: [1.0, 0.0, 0.0]
             Scale: 1.0

     - Name: door
       MapCharacter: D
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/door-1.png
         Block2D:
           - Shape: square
             Color: [0.0, 0.0, 0.5]
             Scale: 1.0

     - Name: open_door
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/open_door-1.png
         Block2D:
           - Shape: square
             Color: [0.0, 0.0, 0.0]
             Scale: 0.0

     - Name: doggo
       MapCharacter: d
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/avatars/doggo1.png
         Block2D:
           - Shape: triangle
             Color: [0.2, 0.2, 0.2]
             Scale: 0.7

     - Name: chair
       MapCharacter: c
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/chair-1.png
         Block2D:
           - Shape: triangle
             Color: [0.4, 0.0, 0.4]
             Scale: 0.6

     - Name: table
       MapCharacter: t
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/table-1.png
         Block2D:
           - Shape: square
             Color: [0.4, 0.4, 0.4]
             Scale: 0.8

     - Name: bookshelf
       MapCharacter: b
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/bookshelf-1.png
         Block2D:
           - Shape: square
             Color: [0.0, 0.4, 0.4]
             Scale: 0.8

     - Name: key
       MapCharacter: k
       Observers:
         Sprite2D:
           - Image: oryx/oryx_fantasy/key-3.png
         Block2D:
           - Shape: triangle
             Color: [1.0, 1.0, 0.0]
             Scale: 0.5


