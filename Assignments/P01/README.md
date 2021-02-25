#### Program 01 - Game

### Loic Konan

#### Description

We will be organizing our code and applying some OOP techniques on subsequent assignments.

### Files

|  #  | File                                 | Description                                         |
| :-: | ------------------------------------ | --------------------------------------------------- |
|  1  | [Banner](Banner)                     | Banner for Assignment                               |

**Player**
>
    - Is a circle shape
    - But could be another shape or sprite (later).
    - Size is configurable
    - Color is configurable
    - Starting location also configurable
    - However for this "game" player starts at middle left of screen.
    - Moves up and down (1 direction only for now) using up and down arrows (additional keys can be set to do same thing).
    - A player can however possibly move other directions as well (in later installments).

**Debris**
>
    - Is a rectangle shape
    - But could be another shape or sprite (later).
    - Size is configurable
    - Color is configurable
    - Starting location also configurable
    - Moves them from right to left starting at a random Y location just off right side of screen.
    - The size should be random between some min and max value.
    - The speed should also be random set between some min and max value.
    - The frequency and speed should slowly increase over time. Enough that after ONE minute of play, it should be impossible

**Scoring**
>
    - When a Player comes collides with Debris score is negatively effected.
    - When a piece of Debris leaves game screen (on the left), score is positively effected.

**Text Output**
>
    - Score gets displayed somewhere on the screen.
    - Font is configurable.
    - Location is configurable.
    - Color is configurable.
    - Size is configurable.
