#include <cstdio>
#include "shapefil.h"

int main() {

    // open the Shapefile
    const char* shapefilePath = "uk_map.shp";
    SHPHandle shp = SHPOpen(shapefilePath, "rb");

    if (shp == nullptr) {
        printf("Failed to open Shapefile.\n");
        return 1;
    }

    // get the number of features in the Shapefile
    int numEntities, shapeType;
    SHPGetInfo(shp, &numEntities, &shapeType, nullptr, nullptr);

    printf("Number of entities in the Shapefile: %d\n", numEntities);
    printf("Shape Type: %d\n", shapeType);

    // loop through each entity
    for (int i = 0; i < numEntities; ++i) {
        SHPObject* shpObject = SHPReadObject(shp, i);

        // access the geometry and other information
        printf("Entity %d:\n", i + 1);
        printf("  Type: %d\n", shpObject->nSHPType);

        // cleanup the SHPObject
        SHPDestroyObject(shpObject);
    }

    // close the Shapefile
    SHPClose(shp);

    return 0;
}
