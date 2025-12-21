namespace targets {
    class Alien {
    public:
        int x_coordinate;
        int y_coordinate;

        Alien(int x_coordinate, int y_coordinate) {
            this->x_coordinate = x_coordinate;
            this->y_coordinate = y_coordinate;
        }

        int get_health() const;

        bool hit();

        bool is_alive();

        bool teleport(int new_x, int new_y);

        bool collision_detection(const Alien &other);

    private:
        int health = 3;
    };


    int Alien::get_health() const {
        return health;
    }

    bool Alien::hit() {
        //you can't use WHILE in this place
        if (health > 0) {
            --health;
        }
        return true;
    }

    bool Alien::is_alive() {
        return health > 0;
    }

    bool Alien::teleport(int new_x, int new_y) {
        x_coordinate = new_x;
        y_coordinate = new_y;
        return true;
    }

    bool Alien::collision_detection(const Alien &other) {
        return x_coordinate == other.x_coordinate && y_coordinate == other.y_coordinate;
    }
} // namespace targets
