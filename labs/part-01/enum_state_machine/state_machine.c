#include <stdio.h>

typedef enum {GREEN, YELLOW, RED} TrafficLightState;

static const char *get_traffic_light_state(TrafficLightState state) {
    switch (state) {
        case GREEN: return "GREEN";
        case YELLOW: return "YELLOW";
        case RED: return "RED";
    }

    return "Invalid";
}

static TrafficLightState update_traffic_light_states(TrafficLightState state) {
    switch (state) {
        case GREEN: return YELLOW;
        case YELLOW: return RED;
        case RED: return GREEN;
    }

    return -1;
}

int main() {
    printf("%s = %i, %s = %i, %s = %i\n", get_traffic_light_state(GREEN), GREEN, get_traffic_light_state(YELLOW), YELLOW, get_traffic_light_state(RED), RED);
    TrafficLightState street_light1 = RED;
    printf("Current state of light: %s\n\n", get_traffic_light_state(street_light1));

    for (int i=0; i<5; i++) {
        TrafficLightState old_state = street_light1;
        street_light1 = update_traffic_light_states(street_light1);
        printf("Street Light Updated: %s -> %s\n", get_traffic_light_state(old_state), get_traffic_light_state(street_light1));
    }
    return 0;
}

/*You can explain: what integer an enum constant is,
 *why default: can hide bugs, and why a state machine
 *is easier to test than a pile of if flags
 *----------
 *Enum constant basically puts labels on the integers making it easier to read
 *and understand what that integer represents. It adds context so state can be easily figured out.
 *
 *default case can hide bugs because compiler will not catch a missing case, unhandled value from enum.
 *
 *pile of if flags make it more difficult to understand and control state.
 */



/* ^ too lazy to fix above answer, here is what AI said. It's also in the ./05-notes.md
 * 1. "What integer an enum constant is": partial.
You explained why enums exist (readable labels with context). That's true, but the question asks what integer a constant is. What's missing:
- The values start at 0 and go up by 1 unless you assign them: GREEN is 0, YELLOW 1, RED 2. With {A = 10, B}, B is 11. 05-notes.md §1 shows this, and its author compiled and ran that example.
- Each constant has type int. That's why you can print GREEN with %i.
- C doesn't check enum values. TrafficLightState s = 42; compiles without a warning, because the variable is just an integer underneath. That's why your functions need the return "Invalid"; and return -1; fallbacks after the switch.

Try to say all of that in one sentence, like "an enum constant is a named int…".

2. "Why default: can hide bugs": good.
You have the core idea: with default:, the compiler no longer warns about a case you forgot. To make it complete, add what happens at runtime. The forgotten value quietly runs the default: code, so the program gives a wrong answer with no warning and no crash. In 05-notes.md §3 the forgotten DOOR_LOCKED quietly prints as "other". Also name the warning that gets switched off: -Wswitch, from -Wall.

3. "Why a state machine is easier to test than a pile of if flags": too vague.
"More difficult to understand and control" is true of plenty of bad code. It doesn't say what's different about flags. The specific reasons:
- Flags allow impossible combinations. Two bools give four combinations, including nonsense like "open and locked". One enum variable holds exactly one state, so the impossible ones can't be stored.
- The test cases are a finite list. For your light, you test 3 states × 1 transition = 3 cases: GREEN→YELLOW, YELLOW→RED, RED→GREEN. With flags you'd have to test every combination, including the ones that shouldn't exist.
- The rules live in one place, the switch in update_traffic_light_states. They aren't spread across
  ifs all over the program.

Rewrite 1 and 3 with those points  pass. You don't need to copy my wording.
 */