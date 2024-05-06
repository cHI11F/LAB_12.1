#include "pch.h"
#include "CppUnitTest.h"
#include "../LAB_12.1/LAB_12.1.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
    TEST_CLASS(UnitTest1)
    {
    public:

        TEST_METHOD(TestLinkedListCreationAndDeletion)
        {
            // Arrange
            Elem* p = new Elem; // Вузол 'p'
            p->info = 1; // Вузол 1
            p->link1 = new Elem; // Вузол 1 вказує на Вузол 2
            p->link1->info = 2; // Вузол 2
            p->link2 = new Elem; // Вузол 1 вказує на Вузол 4
            p->link2->info = 4; // Вузол 4

            p->link2->link2 = new Elem; // Вузол 4 вказує на Вузол 3
            p->link2->link2->info = 3; // Вузол 3

            p->link1->link2 = p->link2->link2; // Вузол 2 вказує назад на Вузол 3
            p->link2->link1 = p; // Вузол 4 вказує назад на Вузол 'p'

            // Act
            // Видалення вузлів
            delete p->link1; // Видалити Вузол 2
            delete p->link2->link2; // Видалити Вузол 3
            delete p->link2; // Видалити Вузол 4
            delete p; // Видалити Вузол 1 (або 'p')
        }
    };
}
