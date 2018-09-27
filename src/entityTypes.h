#ifndef entityTypes_h
#define entityTypes_h

typedef uint8_t EntityType;

// max of 32 entities, and max of 8 ids per room
const EntityType ENTITY_MASK = 0b00011111;
const EntityType ENTITY_MISC_MASK = 0b00000111;

// items the player can use, anything with ID less than 8
// can be stored in a chest
const EntityType SWORD = 0;
const EntityType BOOMERANG = 1;
const EntityType BOMB = 2;
const EntityType RING = 3;
const EntityType KEY = 4;
const EntityType HEART = 5;
const EntityType BOSS_KEY = 6;
const EntityType CHEST = 7;

// enemies, to be named
const EntityType BLOB = 8;
const EntityType BAT = 9;
const EntityType SKELETON = 10;

// bosses
const EntityType GIANT_BAT = 11;
const EntityType BLOB_MOTHER = 12;
const EntityType NEMESIS = 13;

// things related to navigating maps
// and interacting with the world
const EntityType TELEPORTER = 14; // aka a door
const EntityType LOCK = 15;
const EntityType BOSS_LOCK = 16;

// projectiles
const EntityType PROJECTILE = 17;
const EntityType EXPLOSION = 18; 
// misc
const EntityType SECRET_WALL = 19;
const EntityType TRIGGER_DOOR = 20;
const EntityType SWITCH = 21;
const EntityType POT = 22;
const EntityType SUNKEN_BRIDGE = 23;
const EntityType TORCH = 24;

const uint8_t NUM_ENTITIES = TORCH + 1;

// these are entities in a sense, but they don't fully participate
// in the entity system
const EntityType ITEM_DROP = 253;
const EntityType PLAYER = 254;
const EntityType UNSET = 255;

const EntityType SAD_FACE = 7;
const EntityType HAPPY_FACE = 8;

enum RoomType: uint8_t {
    NORMAL,
    SLAM_SHUT,
    LAST_ENEMY_HAS_KEY,
    LAST_ENEMY_HAS_BOSS_KEY,
    THREE_SWITCHES_ONE_BOOMERANG,
    OPEN_CHESTS_IN_RIGHT_ORDER,
    LAST_TORCH_OPENS_DOORS
};

#endif

