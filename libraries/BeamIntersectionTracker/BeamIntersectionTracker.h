class BeamIntersectionTracker
{
private:
    String buffer, command = "";
    unsigned long changedAt = 0;

    const int bufferTime = 10;
    const int resetTime = 1000;

    enum State {
        BEGIN = 0,
        L1,
        R1,
        L0,
        R0
    };

    enum Direction {
        NONE = 0,
        IN = 1,
        OUT
    };

    State state = BEGIN;
    Direction direction = NONE;

    void (*callback)(int);

public:
    bool debug = false;

    BeamIntersectionTracker(void (*callback)(int))
    {
        this->callback = callback;
    }

    void loop()
    {
        unsigned long current = millis();

        if (state == BEGIN) {
            return;
        }

        if (current - changedAt >= resetTime) {
            state = BEGIN;
            direction = NONE;
            Serial.println("Reset");
        }
    }

    void setState(State state)
    {
        unsigned long current = millis();

        if (debug) {
            Serial.print(this->state);
            Serial.print(" -> ");
            Serial.print(state);
            Serial.print("|");
            Serial.println(current - changedAt);
        }

        this->state = state;
        this->changedAt = current;
    }

    void intersection(int beam, int value)
    {
        State newState;

        if (beam == 1 && value == HIGH) {
            newState = R1;
        } else if (beam == 1 && value == LOW) {
            newState = R0;
        } else if (beam == 2 && value == HIGH) {
            newState = L1;
        } else if (beam == 2 && value == LOW) {
            newState = L0;
        }

        if (debug) {
            Serial.print(this->state);
            Serial.print(" ? ");
            Serial.println(newState);
        }

        if (direction == NONE) {

            switch (newState) {
                case L1:

                    if (state == BEGIN) {
                        this->setState(newState);
                        this->direction = IN;
                    }

                    break;

                case R1:

                    if (state == BEGIN) {
                        this->setState(newState);
                        this->direction = OUT;
                    }

                    break;
            }

        } else if (direction == IN) {

            switch (newState) {
                case R1:

                    if (state == L1) {
                        this->setState(newState);
                    }

                    break;

                case L0:

                    if (state == R1) {
                        this->setState(newState);
                    }
                    break;

                case R0:

                    if (state == L0) {
                        this->setState(newState);
                        this->callback(1);
                    }
                    break;
            }

        } else if (direction == OUT) {

            switch (newState) {
                case L1:

                    if (state == R1) {
                        this->setState(newState);
                    }

                    break;

                case R0:

                    if (state == L1) {
                        this->setState(newState);
                    }

                    break;

                case L0:

                    if (state == R0) {
                        this->setState(newState);
                        this->callback(2);
                    }
                    break;

            }

        }
    }
};

