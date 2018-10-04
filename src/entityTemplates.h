#ifndef entityTemplates_h
#define entityTemplates_h

#include <Arduino.h>
#include "entityTypes.h"
#include "entity.h"
#include "spriteBitmaps.h"
#include "tileBitmaps.h"

#include "entities/commonEnemy.h"
#include "entities/blob.h"
#include "entities/bat.h"
#include "entities/skeleton.h"
#include "entities/sword.h"
#include "entities/boomerang.h"
#include "entities/bomb.h"
#include "entities/explosion.h"
#include "entities/secretWall.h"
#include "entities/lock.h"
#include "entities/pot.h"
#include "entities/projectile.h"
#include "entities/torch.h"
#include "entities/chest.h"
#include "entities/triggerDoor.h"
#include "entities/switch.h"
#include "entities/blobMother.h"
#include "entities/nemesis.h"

const uint8_t NUM_ENTITY_PROPS = 4;
const uint8_t NUM_ENTITY_POINTERS = 3;

/**
 * Packs width and height into one byte. Since nibbles have a range of 0-15,
 * it first subtracts one from the value. When unpacking, need to add 1 back on
 */
constexpr uint8_t widthAndHeight(uint8_t width, uint8_t height) {
    return (width - 1) << 4 | (height - 1);
}

/**
 * Packs health and damage into one byte
 */
constexpr uint8_t healthAndDamage(uint8_t health, uint8_t damage) {
    return (health << 4) | damage;
}

const uint8_t PROGMEM entityProperties[NUM_ENTITIES * NUM_ENTITY_PROPS] = {
    // 0 SWORD
    widthAndHeight(16, 16),
    healthAndDamage(0, 1),
    20,             // duration
    true,           // needsMask

    // 1, BOOMERANG
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    20,
    true,

    // 2, BOMB
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    150,
    true,

    // 3, KEY
    widthAndHeight(3, 8),
    healthAndDamage(0, 0),
    0,
    true,

    // 4, HEART
    widthAndHeight(7, 8),
    healthAndDamage(0, 0),
    180,
    true,

    // 5, CHEST
    widthAndHeight(14, 8),
    healthAndDamage(0, 0),
    20,
    false,

    // 6, BLOB
    widthAndHeight(8, 8),
    healthAndDamage(2, 1),
    0,          // duration
    true,       // needsMask

    // 7, BAT
    widthAndHeight(8, 8),
    healthAndDamage(1, 1),
    0,
    true,

    // 8, SKELETON
    widthAndHeight(16, 16),
    healthAndDamage(2, 1),
    0,
    true,

    // 9, GIANT_BAT
    widthAndHeight(16, 16),
    healthAndDamage(8, 1),
    10,
    true,

    // 10, BLOB_MOTHER
    widthAndHeight(15, 16),
    healthAndDamage(6, 1),
    10,
    true,

    // 11, NEMESIS
    widthAndHeight(8, 8),
    healthAndDamage(15, 0),
    30,
    true,

    // 12, TELEPORTER
    widthAndHeight(16, 4),
    healthAndDamage(0, 0),
    0,
    false,

    // 13, LOCK
    widthAndHeight(16, 16),
    healthAndDamage(1, 0),
    0,
    false,

    // 14, BOSS_LOCK
    widthAndHeight(16, 16),
    healthAndDamage(1, 0),
    0,
    false,

    // 15, PROJECTILE
    widthAndHeight(8, 8),
    healthAndDamage(0 , 2),
    20,
    false,

    // 16, EXPLOSION
    widthAndHeight(16, 16),
    healthAndDamage(0 , 1),
    20,
    false,

    // 17, SECRET_WALL
    widthAndHeight(16, 16),
    healthAndDamage(1, 0),
    0,
    false,

    // 18, TRIGGER_DOOR
    widthAndHeight(16, 8),
    healthAndDamage(0, 0),
    20,
    false,

    // 19, SWITCH
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    false,

    // 20, POT
    widthAndHeight(8, 8),
    healthAndDamage(0, 0),
    0,
    false,

    // 21, SUNKEN_BRIDGE
    widthAndHeight(0, 0),
    healthAndDamage(0, 0),
    0,
    false,

    // 22, TORCH
    widthAndHeight(8, 8),
    healthAndDamage(1, 0),
    0,
    false
};

const void* const PROGMEM entityPointers[NUM_ENTITIES * NUM_ENTITY_POINTERS] = {
    // 0, SWORD
    sword_plus_mask,    // tiles
    (void*)Sword::update,      // update
    NULL,               // onCollide


    // 1, BOOMERANG
    boomerang_plus_mask,
    (void*)Boomerang::update,
    (void*)Boomerang::onCollide,

    // 2, BOMB
    bomb_plus_mask,
    (void*)Bomb::update,
    NULL,

    // 3, KEY
    key_plus_mask,
    NULL,
    NULL,

    // 4, HEART
    heart_plus_mask,
    NULL,
    NULL,

    // 5, CHEST
    chest_tiles,
    (void*)Chest::update,
    NULL,

    // 6, BLOB
    blob_plus_mask,
    (void*)Blob::update,
    (void*)CommonEnemy::onCollide,

    // 7, BAT
    bat_plus_mask,
    (void*)Bat::update,
    (void*)Bat::onCollide,

    // 8, SKELETON
    skeleton_plus_mask,
    (void*)Skeleton::update,
    (void*)CommonEnemy::onCollide,

    // 9, GIANT_BAT
    giantBat_plus_mask,
    (void*)Bat::update,
    (void*)Bat::onCollide,

    // 10, BLOB_MOTHER
    blobMother_plus_mask,
    (void*)BlobMother::update,
    (void*)CommonEnemy::onCollide,

    // 11, NEMESIS
    player_plus_mask,
    (void*)Nemesis::update,
    (void*)Nemesis::onCollide,

    // 12, TELEPORTER
    NULL,
    NULL,
    NULL,

    // 13, LOCK
    lock_tiles,
    NULL,
    (void*)Lock::onCollide,

    // 14, BOSS_LOCK
    bossLock_tiles,
    NULL,
    (void*)Lock::onCollide,

    // 15, PROJECTILE
    projectile_tiles,
    (void*)Projectile::update,
    NULL,

    // 16, EXPLOSION
    explosion_tiles,
    (void*)Explosion::update,
    NULL,

    // 17, SECRET_WALL
    secretWall_tiles,
    NULL,
    (void*)SecretWall::onCollide,

    // 18, TRIGGER_DOOR
    NULL,
    (void*)TriggerDoor::update,
    (void*)TriggerDoor::onCollide,

    // 19, SWITCH
    switch_tiles,
    NULL,
    (void*)Switch::onCollide,

    // 20, POT
    pot_tiles,
    NULL,
    (void*)Pot::onCollide,

    // 21, SUNKEN_BRIDGE
    NULL,
    NULL,
    NULL,

    // 22, TORCH
    torch_tiles,
    (void*)Torch::update,
    (void*)Torch::onCollide
};

void loadEntity(Entity& entity, EntityType entityType);

#endif

