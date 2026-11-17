# Core idea

Combined exploration + dungeon crawler, so above-ground and underground bits. The actual start and lore and shit is TBD

* Semi-open mysical world, much more heavy on the fantasy bits than a fair few other RPGs
* Two dungeon tiers; one for smaller regional annoyances, one for the bigger badder bosses

## Some specific mechanics

* Learned combat abilities/spells, both through the standard routes (trainers and libraries), but also observation
  * I'm not entirely sure how the latter option is going to integrate into the combat loop, especially since I want real-time stuff
* Somewhat inspired by DnD, I want there to be reasons to interact with lore. Since we need libraries anyway, having the ability to do downtime to train both primary combat abilities and secondary abilities while in cities sounds like a good idea 
* Cities are semi-safe zones. The chance of getting attacked by demons in cities or whatever is slim, but never zero (or something)
* I think it makes sense to start off with one class, but setting the system up to be generic enough that it can expand. 
  * I'm somewhat partial to start with a druid, in part because it seems like a flexible class to write lore around (plus, it makes sense since lots of animals and nature-leaning fantasy bits), and in part because WoW druids are fun :p Won't be the same broad design though, I have a few things I want to do different
* I want a scale where short time periods don't matter as much. If the journey is like 2 years or whatever, resting for a week in a town is going to be a requirement from time to time. 

### Combat loop

* Real-time, standard weapon use is automatic, but comparatively low damage 
* Skills require mana or unnamed action point equivalents for non-magical abilities, and is the main damage output 
* Bosses use the standard cliches of highlighting where the fire is going
* All combat is going to be a combination of AoE and ray mechanics, for the lack of a better term, so the skill bits are don't stand in the fire and don't stand in the blast cone/line/squirkle/whatever the fuck
* Strategy is functionally planned in advance
  * Each class has a subset of specializations that can be swapped (just not during combat for obvious reasons)
  * Different specializations allow different moves, even if the player knows all of them (you can't do like certain kinds of very dynamic martial arts in full plate armour)
  * This doesn't _have_ to be specializations in the sense of the word, it could just be that certain equipment allows different playstyles. You need a wand to cast more advanced spells, plate armour does not conduct magic or whatever, etc..
  * More research is required
  * I don't know how much resolution we want here; I don't think a damage type system makes much sense outside maybe effects (like a sword can poison if it's coated with poison, etc.)

### Leveling and skill mechanics

* Standard XP + skill points for certain abilities 
  * I don't know what these should be yet; maybe not as fine-grained as "gib fireball", but rather working towards progress on entire skill groups
  * like, "Advance magic" to unlock another spell slot or whatever, which can then be filled with learned or discovered magic. 
  * Constraining skill slots at minimum in different categories would allow strategic decisions based on spell selection
  * I also like the idea of upgradable spells, so rather than unlocking more spells, you get better at putting fire into the ball or whatever
* Separate skill combat and non-combat skill points
  * Scales damage or efficiency or hit rates or possibly mana regen or mana equivalents
* A combination of cast time (or cast time equivalent) and recovery time/global cooldown (plus obviously spell cooldown) seems like the best way to balance the more powerful abilities?

### Gear

* "Non-compatible" gear, so different gear can be incompatible with specializations (not necessarily outright incompatible either, but functionally based on what attributes are affected)
* Repair mechanics, no gear swapping during combat (not counting consumables or equivalent)
* Gear progression should be a thing, though I'm not entirely sure how the economy of gear would work. If we go with the life essence is currency-approach, that could also mean there's tiers of crystals and those have different magic applications
  * Levels might also be more accurate, I don't want to limit it by like named tiers, because that heavily locks down future expansion
    * See: WoW gear somehow being mythic until the next BBEG shows up, then the mythic gear is fucking trash and some common gear dropped in the intro sequence beats all of the previous mythic gear 
    * I.e. rarity should be independent of levels, possibly a subcategory (so level 10 mythic >> level 10 common)
    * A lot more work is required on the exact gear mechanics; I think it makes sense to start simple and expand as needed.

## Quests and side quests

* The main questlines are mostly (very oversimplified) "kill the BBEG" or "do things necessary to eventually kill the BBEG"
  * The main questline does not need to be strictly linear, so it can still contain side quest shaped quests
* Side quests are a combination of kill the local miniboss terrorizing the area (not necessarily affiliated with the BBEG faction), and stuff furthering secondary skills (so like, "help us pick these fresh strawbs" or rebuilding shit or whatever)
  * These are much more focused on individual needs and similar rather than the whole impending regional doom
  * I think this is where it makes sense to fit in secondary skills for alternate "endings"; not all the local bad factions have to be fundamentally and irrecoverably bad

## Misc unfinished thoughts

* I'm not sure how I want the economy to work. The good 'ol copper/silver/gold does *work*, but why would a bunch of random creatures in dungeons built on evil or whatever have acquired any of it?
  * Some dungeon animes build on a concept of crystals that either are the economy or get turned into other stuff that's then worth standard economy monetary values. Something something life essence?
  * This would also make something like a bank make sense, unless we just gesture it away as being portals
* I do think there's some value to looking into non-monetary economy mechanics; how does ${insert item} get from the city that produces it to the random town that you happen to be in?
* Multi-"people" raids: how do? Would be kinda cool if you could recruit other (non-player) adventurers for one-off massive fights or whatever. Would make the fights feel more immersive anyway

## Open questions

* The quest categories are split the way they are to make the world feel more alive and like it doesn't actively depend on whatever big evil thing is going on. This also means that the BBEG faction is driven out of an area once all the main quests are done, so secondary quests don't depend on game state to be completable. I want to avoid region lockout or having perpetual evil because it's the only way quests can be kept alive. 
* Inverse region lockout is still a bit of a concern; I don't want there to be a true completion state where anything that could go wrong is conveniently fixed specifically until the next BBEG is made. I'm also not sure how to implement this without ending up with quest churn
  * The goal isn't for there to always be something to do, just for the cities to feel alive. This may be solved with a quest board basically. Like, more "get involved in whatever the city is doing", not "we need you in particular because no one else can pick up this box of seeds and move it 50m that way"

## Misc scope creep

* Having the gameplay be region-bound would allow expansions with new content if this rabbit hole goes that deep. Expansions wouldn't need to use the same core model either
* I want a city to be outright destroyed at some point, preferably not in the preamble lore, though that does work if actually implementing that is too much of a pain

