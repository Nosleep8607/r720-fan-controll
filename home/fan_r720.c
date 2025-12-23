/*
 * Original author: Lareira Digital <info@lareira.digital>
 * MIT License
 *
 * This C version is a rewrite of the fan_r720.sh script
 * for clean installation in Debian.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s [enableauto|disableauto|set N]\n", argv[0]);
        return 1;
    }

    char command[256];

    if (strcmp(argv[1], "enableauto") == 0) {
        snprintf(command, sizeof(command), "ipmitool raw 0x30 0x30 0x01 0x01");
        system(command);
    } else if (strcmp(argv[1], "disableauto") == 0) {
        snprintf(command, sizeof(command), "ipmitool raw 0x30 0x30 0x01 0x00");
        system(command);
    } else if (strcmp(argv[1], "set") == 0 && argc == 3) {
        int value = atoi(argv[2]);
        if (value < 0 || value > 255) {
            fprintf(stderr, "ERROR: Fan speed must be 0-255\n");
            return 1;
        }
        // Disable automatic fan control first
        system("ipmitool raw 0x30 0x30 0x01 0x00");
        // Set fan speed
        snprintf(command, sizeof(command), "ipmitool raw 0x30 0x30 0x02 0xff 0x%x", value);
        system(command);
    } else {
        fprintf(stderr, "ERROR: Invalid option. Use enableauto, disableauto, or set N\n");
        return 1;
    }

    return 0;
}
