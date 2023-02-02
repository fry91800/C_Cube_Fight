#ifndef PHYSICS_H
#define PHYSICS_H

#include "player.h"
#include  "item.h"
#include "boundary.h"
void apply_physics(struct player **players, struct item **items, struct boundary **boundaries);

#endif /* !PHYSICS_H */