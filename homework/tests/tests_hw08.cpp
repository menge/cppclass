#include "hw08.h"
#include "gtest/gtest.h"
#include "gtest/gtest_prod.h"
#include <stdexcept>
#include <iostream>

namespace cppclass
{
    class BasicLinkedListTest : public ::testing::Test {
    protected:
        BasicLinkedListTest() {}
        virtual ~BasicLinkedListTest() {}
        virtual void SetUp() {}
        virtual void TearDown() {}

        virtual void Validate(const LinkedList &ll)
        {
            auto head = ll.at(0);
            auto p = head;

            if (ll.get_size() == 0)
                return;

            ASSERT_EQ(head->prev, nullptr);

            for (; p->next != nullptr; p = p->next)
            {
                ASSERT_EQ(p, p->next->prev);
                if (p->prev != nullptr)
                {
                    ASSERT_EQ(p, p->prev->next);
                }
            }

            if (p->prev != nullptr)
            {
                ASSERT_EQ(p, p->prev->next);
            }
            ASSERT_EQ(p->next, nullptr);
        }
    };

    TEST_F(BasicLinkedListTest, DefaultConstructor)
    {
        LinkedList ll;
        EXPECT_EQ(ll.m_head, nullptr);
        EXPECT_EQ(ll.m_tail, nullptr);
        EXPECT_EQ(ll.m_size, 0);
    }

    TEST_F(BasicLinkedListTest, GetSizeWithMutating)
    {
        LinkedList ll;

        EXPECT_EQ(ll.get_size(), 0);
        ll.m_size = 200;
        EXPECT_EQ(ll.get_size(), 200);
        ll.m_size = 0;
        EXPECT_EQ(ll.get_size(), 0);
    }

    TEST_F(BasicLinkedListTest, HeadTailMutation)
    {
        {
            LinkedList ll;

            EXPECT_EQ(ll.m_head, nullptr);
            EXPECT_EQ(ll.m_tail, nullptr);
            ll.m_head = (cppclass::LinkedList::Node *)0xabcddcba;
            ll.m_tail = (cppclass::LinkedList::Node *)0xdeadbeef;
            EXPECT_EQ(ll.m_head, (cppclass::LinkedList::Node *)0xabcddcba);
            EXPECT_EQ(ll.m_tail, (cppclass::LinkedList::Node *)0xdeadbeef);
            ll.m_head = nullptr;
            ll.m_tail = nullptr;
            EXPECT_EQ(ll.m_head, nullptr);
            EXPECT_EQ(ll.m_tail, nullptr);
        }
        {
            LinkedList ll;

            auto ptr = ll.append(0);
            EXPECT_EQ(ll.m_head, ptr);
            EXPECT_EQ(ll.m_tail, ptr);

            auto ptr2 = ll.append(1);
            EXPECT_EQ(ll.m_head, ptr);
            EXPECT_EQ(ll.m_tail, ptr2);

            auto ptr3 = ll.append(2, ptr2);
            EXPECT_EQ(ll.m_head, ptr);
            EXPECT_EQ(ll.m_tail, ptr3);
        }
        {
            LinkedList ll;

            auto ptr = ll.insert(0);
            EXPECT_EQ(ll.m_head, ptr);
            EXPECT_EQ(ll.m_tail, ptr);

            auto ptr2 = ll.insert(1);
            EXPECT_EQ(ll.m_head, ptr2);
            EXPECT_EQ(ll.m_tail, ptr);

            auto ptr3 = ll.insert(2, ptr);
            EXPECT_EQ(ll.m_head, ptr2);
            EXPECT_EQ(ll.m_tail, ptr);
        }
    }

    TEST_F(BasicLinkedListTest, Append)
    {
        LinkedList ll;

        // empty append
        EXPECT_EQ(ll.get_size(), 0);
        auto ptr1 = ll.append(0);
        ASSERT_NE(ptr1, nullptr);
        EXPECT_EQ(ll.get_size(), 1);
        EXPECT_EQ(ptr1->data, 0);
        EXPECT_EQ(ptr1->next, nullptr);
        EXPECT_EQ(ptr1->prev, nullptr);

        // append at end of list
        auto ptr2 = ll.append(1);
        ASSERT_NE(ptr2, nullptr);
        EXPECT_EQ(ll.get_size(), 2);
        EXPECT_EQ(ptr2->data, 1);
        EXPECT_EQ(ptr2->next, nullptr);
        EXPECT_EQ(ptr2->prev, ptr1);
        EXPECT_EQ(ptr1->next, ptr2);

        // append at beginning of list
        auto ptr3 = ll.append(2, ptr1);
        ASSERT_NE(ptr3, nullptr);
        EXPECT_EQ(ll.get_size(), 3);
        EXPECT_EQ(ptr3->data, 2);
        EXPECT_EQ(ptr3->next, ptr2);
        EXPECT_EQ(ptr3->prev, ptr1);
        EXPECT_EQ(ptr2->prev, ptr3);
        EXPECT_EQ(ptr1->next, ptr3);
    }

    TEST_F(BasicLinkedListTest, Insert)
    {
        LinkedList ll;

        // empty append
        EXPECT_EQ(ll.get_size(), 0);
        auto ptr1 = ll.insert(0);
        ASSERT_NE(ptr1, nullptr);
        EXPECT_EQ(ll.get_size(), 1);
        EXPECT_EQ(ptr1->data, 0);
        EXPECT_EQ(ptr1->next, nullptr);
        EXPECT_EQ(ptr1->prev, nullptr);

        // insert at beginning of list
        auto ptr2 = ll.insert(1);
        ASSERT_NE(ptr2, nullptr);
        EXPECT_EQ(ll.get_size(), 2);
        EXPECT_EQ(ptr2->data, 1);
        EXPECT_EQ(ptr2->next, ptr1);
        EXPECT_EQ(ptr2->prev, nullptr);
        EXPECT_EQ(ptr1->prev, ptr2);

        // insert at end of list
        auto ptr3 = ll.insert(2, ptr1);
        ASSERT_NE(ptr3, nullptr);
        EXPECT_EQ(ll.get_size(), 3);
        EXPECT_EQ(ptr3->data, 2);
        EXPECT_EQ(ptr3->prev, ptr2);
        EXPECT_EQ(ptr3->next, ptr1);
        EXPECT_EQ(ptr2->next, ptr3);
        EXPECT_EQ(ptr1->prev, ptr3);
    }

    TEST_F(BasicLinkedListTest, Search)
    {
        LinkedList ll;

        auto ptr0 = ll.append(0);
        auto ptr1 = ll.append(1);
        auto ptr2 = ll.append(2);

        // Find existing
        EXPECT_EQ(ll.search(0), ptr0);
        EXPECT_EQ(ll.search(1), ptr1);
        EXPECT_EQ(ll.search(2), ptr2);

        // Find non-existing
        EXPECT_EQ(ll.search(3), nullptr);
        EXPECT_EQ(ll.search(-1), nullptr);

        // insert same data and find that
        auto ptr3 = ll.insert(2);
        EXPECT_EQ(ll.search(2), ptr3);
    }

    TEST_F(BasicLinkedListTest, At)
    {
        LinkedList ll;

        auto ptr0 = ll.append(0);
        auto ptr1 = ll.append(1);
        auto ptr2 = ll.append(2);

        // Find existing
        EXPECT_EQ(ll.at(0), ptr0);
        EXPECT_EQ(ll.at(1), ptr1);
        EXPECT_EQ(ll.at(2), ptr2);

        // Find non-existing
        EXPECT_EQ(ll.at(3), nullptr);
        EXPECT_EQ(ll.at(100), nullptr);

        // insert same data and find that
        auto ptr3 = ll.insert(2);
        EXPECT_EQ(ll.at(0), ptr3);
        EXPECT_EQ(ll.at(1), ptr0);
        EXPECT_EQ(ll.at(2), ptr1);
        EXPECT_EQ(ll.at(3), ptr2);
        EXPECT_EQ(ll.at(4), nullptr);
    }

    TEST_F(BasicLinkedListTest, MoveConstructor)
    {
        LinkedList ll;

        auto ptr0 = ll.append(0);
        auto ptr1 = ll.append(1);
        auto ptr2 = ll.append(2);
        auto ptr3 = ll.append(3);
        auto ptr4 = ll.append(4);

        LinkedList moved(std::move(ll));

        EXPECT_EQ(moved.at(0), ptr0);
        EXPECT_EQ(moved.at(1), ptr1);
        EXPECT_EQ(moved.at(2), ptr2);
        EXPECT_EQ(moved.at(3), ptr3);
        EXPECT_EQ(moved.at(4), ptr4);
        EXPECT_EQ(moved.m_head, ptr0);
        EXPECT_EQ(moved.m_tail, ptr4);
        EXPECT_EQ(moved.m_size, 5);
    }

    TEST_F(BasicLinkedListTest, MultiRandom)
    {
        LinkedList ll;

        const size_t MAX_ITEMS = 512;
        cppclass::LinkedList::Node* ptrs[MAX_ITEMS];

        for (auto i = 0; i < MAX_ITEMS; i++)
        {
            bool insert_mode = rand() % 2;
            cppclass::LinkedList::Node* chosen = nullptr;

            if (i != 0)
            {
                chosen = ptrs[rand() % i];
            }

            if (insert_mode)
                ptrs[i] = ll.insert(i, chosen);
            else
                ptrs[i] = ll.append(i, chosen);
            Validate(ll);
        }
        for (auto i = 0; i < MAX_ITEMS; i++)
        {
            ll.erase(ptrs[i]);
            Validate(ll);
        }
    }

    class LinkedListTest : public BasicLinkedListTest
    {
    protected:
        LinkedList *p_ll;

        LinkedListTest() {}
        virtual ~LinkedListTest() {}
        virtual void SetUp()
        {
            BasicLinkedListTest::SetUp();

            p_ll = new LinkedList();
            p_ll->append(0);
            p_ll->append(1);
            p_ll->append(2);
            p_ll->append(3);
            p_ll->append(4);
        }

        virtual void TearDown()
        {
            BasicLinkedListTest::TearDown();

            delete p_ll;
        }
    };

    TEST_F(LinkedListTest, Setup)
    {
        EXPECT_EQ(p_ll->get_size(), 5);
    }

    TEST_F(LinkedListTest, Erase)
    {
        auto ptr0 = p_ll->m_head;
        auto ptr4 = p_ll->m_tail;

        auto ptr1 = ptr0->next;
        auto ptr2 = ptr1->next;
        auto ptr3 = ptr2->next;

        EXPECT_EQ(ptr0->data, 0);
        EXPECT_EQ(ptr1->data, 1);
        EXPECT_EQ(ptr2->data, 2);
        EXPECT_EQ(ptr3->data, 3);
        EXPECT_EQ(ptr4->data, 4);

        p_ll->erase(ptr2);
        EXPECT_EQ(ptr1->next, ptr3);
        EXPECT_EQ(ptr3->prev, ptr1);
        EXPECT_EQ(p_ll->m_head, ptr0);
        EXPECT_EQ(p_ll->m_tail, ptr4);
        EXPECT_EQ(p_ll->get_size(), 4);

        p_ll->erase(ptr0);
        EXPECT_EQ(ptr1->prev, nullptr);
        EXPECT_EQ(ptr1->next, ptr3);
        EXPECT_EQ(p_ll->m_head, ptr1);
        EXPECT_EQ(p_ll->m_tail, ptr4);
        EXPECT_EQ(p_ll->get_size(), 3);

        p_ll->erase(ptr3);
        EXPECT_EQ(ptr1->next, ptr4);
        EXPECT_EQ(ptr4->prev, ptr1);
        EXPECT_EQ(p_ll->m_head, ptr1);
        EXPECT_EQ(p_ll->m_tail, ptr4);
        EXPECT_EQ(p_ll->get_size(), 2);

        p_ll->erase(ptr4);
        EXPECT_EQ(ptr1->next, nullptr);
        EXPECT_EQ(ptr1->prev, nullptr);
        EXPECT_EQ(p_ll->m_head, ptr1);
        EXPECT_EQ(p_ll->m_tail, ptr1);
        EXPECT_EQ(p_ll->get_size(), 1);

        p_ll->erase(ptr1);
        EXPECT_EQ(p_ll->m_head, nullptr);
        EXPECT_EQ(p_ll->m_tail, nullptr);
        EXPECT_EQ(p_ll->get_size(), 0);
    }

    class MultiLinkedListTest : public LinkedListTest
    {
    protected:
        LinkedList *p_ll_init_list;
        LinkedList *p_ll_cc;
        LinkedList *p_ll_move;

        MultiLinkedListTest() {}
        virtual ~MultiLinkedListTest() {}
        virtual void SetUp()
        {
            LinkedListTest::SetUp();

            int init_list[] = {0, 1, 2, 3, 4};
            p_ll_init_list = new LinkedList(init_list,
                sizeof(init_list)  / sizeof(init_list[0]));

            p_ll_cc = new LinkedList(*p_ll);

            LinkedList stack_ll;
            stack_ll.insert(4);
            stack_ll.insert(3);
            stack_ll.insert(2);
            stack_ll.insert(1);
            stack_ll.insert(0);

            p_ll_move = new LinkedList(std::move(stack_ll));
        }

        virtual void TearDown()
        {
            LinkedListTest::TearDown();

            delete p_ll_init_list;
            delete p_ll_cc;
            delete p_ll_move;
        }
    };

    TEST_F(MultiLinkedListTest, Setup)
    {
        // test for size across all linked lists
        EXPECT_EQ(p_ll->get_size(), 5);
        EXPECT_EQ(p_ll_init_list->get_size(), 5);
        EXPECT_EQ(p_ll_cc->get_size(), 5);
        EXPECT_EQ(p_ll_move->get_size(), 5);

        // test for equality across all linked lists
        EXPECT_EQ(*p_ll, *p_ll_init_list);
        EXPECT_EQ(*p_ll, *p_ll_cc);
        EXPECT_EQ(*p_ll, *p_ll_move);
    }

    TEST_F(MultiLinkedListTest, NotEqual)
    {
        // test for equality across all linked lists
        EXPECT_EQ(*p_ll, *p_ll_init_list);
        EXPECT_EQ(*p_ll, *p_ll_cc);
        EXPECT_EQ(*p_ll, *p_ll_move);

        p_ll_init_list->append(6);
        p_ll_cc->insert(-1);
        p_ll_move->append(7);

        EXPECT_NE(*p_ll, *p_ll_init_list);
        EXPECT_NE(*p_ll, *p_ll_cc);
        EXPECT_NE(*p_ll, *p_ll_move);
    }
}
