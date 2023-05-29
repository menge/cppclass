#include "hanoi.h"

#include <cassert>
#include <iostream>
#include <string>

cppclass::Hanoi::Hanoi(int num)
    : _max_disc_size(num)
    , _num_moves(0)
{
    for (int i = num; i > 0; i--)
    {
        posts[0].emplace_back(i);
    }
}

void cppclass::Hanoi::move(int a, int b)
{
    // Pre-condition: a must not be empty
    assert(posts[a].size() > 0);

    // Pre-condition: width of top item a must be less than top of post b (if not empty)
    if (posts[b].size() > 0)
    {
        assert(posts[a].back() < posts[b].back());
    }

    // Post-condition: top disc of post a will be moved onto top of post b
    posts[b].emplace_back(posts[a].back());
    posts[a].pop_back();

    _num_moves++;
}

std::string operator* (std::string a, unsigned int b)
{
    std::string output = "";
    while (b--)
    {
        output += a;
    }
    return output;
}

void cppclass::Hanoi::print() const
{
    const int POST_SPACING = 2;
    const int POST_WIDTH = 2;
    std::vector< std::vector<std::string> > towers(3);
    int total_lines = 0;


    // Prepare Base
    for (int tower_id = 0; tower_id < towers.size(); tower_id++)
    {
        towers[tower_id].emplace_back(std::string("=") * POST_SPACING +
                                      std::string("=") * _max_disc_size +
                                      std::string("=") * POST_WIDTH +
                                      std::string("=") * _max_disc_size +
                                      std::string("=") * POST_SPACING);
    }
    total_lines++;

    // Prepare Discs
    for (int line = 0; line < _max_disc_size; line++)
    {
        for (int tower_id = 0; tower_id < towers.size(); tower_id++)
        {
            char disc_id = ' ';
            int disc_width = 0;
            char post_char = '|';

            if (line < posts[tower_id].size())
            {
                disc_id = '0' + posts[tower_id][line];
                post_char = disc_id;
                disc_width = posts[tower_id][line];
            }
            int space_to_disc = _max_disc_size - disc_width;

            towers[tower_id].emplace_back(std::string(" ") * POST_SPACING +
                                          std::string(" ") * space_to_disc +
                                          std::string(1, disc_id) * disc_width +
                                          std::string(1, post_char) * POST_WIDTH +
                                          std::string(1, disc_id) * disc_width +
                                          std::string(" ") * space_to_disc +
                                          std::string(" ") * POST_SPACING);
        }
        total_lines++;
    }

    // Print everything
    for (int line = total_lines - 1; line >= 0; line--)
    {
        for (int tower_id = 0; tower_id < towers.size(); tower_id++)
        {
            std::cout << towers[tower_id][line];
        }
        std::cout << std::endl;
    }
    std::cout << "Num moves: " << _num_moves << std::endl;
}
