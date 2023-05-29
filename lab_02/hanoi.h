#include <vector>

namespace cppclass
{
    class Hanoi
    {
    public:
        // Do not allow Hanoi to be called with no parameters
        Hanoi() = delete;

        // Create Towers of Hanoi puzzle where there are num discs on post 0
        Hanoi(int num);

        // Take the top item from post a and move it to post b
        // Pre-condition: a must not be empty
        // Pre-condition: width of top item a must be less than top of post b (if not empty)
        // Post-condition: top disc of post a will be moved onto top of post b
        void move(int a, int b);

        // Print out ascii-text representation of Hanoi state
        void print() const;

    private:
        int _max_disc_size;
        int _num_moves;
        std::vector<int> posts[3];
    };
}
