#include <stdio.h>

typedef enum {GREEN, YELLOW, RED} TrafficLightState;

const char *update_traffic_light_states(TrafficLightState state) {
    switch (state) {
        case GREEN: return "YELLOW";
        case YELLOW: return "RED";
        case RED: return "GREEN";
    }

    return "Invalid";
};

int main() {

    printf("Next: %s\n", update_traffic_light_states(YELLOW));

    return 0;
}