# ToonTanks

## Implemented Features :

#### Movement: 
- Z/S to move Forward/Backward.
- Q/D to rotate the Hull.
- Left mouse Button Release to fire.
- Mouse cursor tell where the tank aim.

#### Projectile
- Is shot toward the turret direction.
- Is subject to gravity.
- Is destroyed on collisions.
- Applied damage to target implementing IDamageable (See T_ReadMe).
- Leave a trail of particles.
- Particles on destruction.

#### Turrets
- Static hull.
- Look at the player tank when in range.
- Shoot at the player tank when in range.

#### UI and Gameloop
- Start UI (countdown) with input blocked.
- Health bar on the player tank and turrets (not updated).
- Level restarts when the player dies.

#### SFX
- Sound played when a shot is fired.
- Sound played when a tank is destroyed.

#### VFX
- Tanks explode on destruction.

## Issues
- Health bars do not look at the camera
- Health bars do not update when a tank take damages.
- There is no UI to signal when the player win or loose.

## Difficulties
- The lack of knowledge on how to implement my first planned architecture in Unreal that lead to a complete rework of it.
- The new architecture make UI complicated to setup and update with the knowledge I have.
- I didn't take enought time to study the GDD so I ended up forgetting some features that would have been easier to implement sooner.

## Design Choices  
All important methods are kept virtual to facilitate the creation of child classes (because inheritance chaos must continue! :D). Additionally, I like to specify both `virtual`  and `override` to keep it crystal clear that these functions come form a parent class.

I chose to treat the tank and turrets as variations of the same base class. Essentially, a turret is a stationary tank that automatically aims at the player.  

Both tanks and turrets inherit from the `ATank` superclass, which provides implementations for `Shoot` and `ApplyDamage`. Other functions (see T_ReadMe) are implemented but behaviorless to avoid forcing child classes to define functions that may not be relevant to their specific behavior.