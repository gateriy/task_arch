п»ї//РїРѕРґРєР»СЋС‡Р°РµРј РјР°РєСЂРѕСЃС‹ catch2

#include "my_list.h"

//--------------РїСЂРѕРІРµСЂРєРё------------

//empty
TEST_CASE("Empty test", "[empty]") {
    
    List class_test;
    class_test.PushBack(1);
   
    CHECK(class_test.Empty() == true);
    CHECK(class_test.Empty() == false);

}

//clear
TEST_CASE("Clear test", "[clear]") {

    List class_test;
    class_test.PushBack(1);

    CHECK(class_test.Empty() == true);
    class_test.Clear();

    CHECK(class_test.Empty() == true);
}

//size
TEST_CASE("Size test", "[size]") {  

    std::cout << "Size test" << std::endl;

    List class_test; 

    for (unsigned long i = 0; i < 100; ++i) {

        class_test.PushBack(i);
        REQUIRE(class_test.Size() == i+1);

        if ((i+1) % 10 == 0) {
            std::cout << class_test.Size()<< " = " << i + 1 << " << good!" << std::endl;
        }
    }
      
    class_test.Clear();
    CHECK(class_test.Empty() == true);
    CHECK(class_test.Size() == 0);

    std::cout << "------------------------------------------" << std::endl;
}

//PushBack
TEST_CASE("PushBack test", "[pushback]") {

    std::cout << "PushBack test" << std::endl;

    List class_test;

    for (unsigned long i = 0; i < 100; ++i) {

        class_test.PushBack(i);
        REQUIRE(class_test.Size() == i + 1);

        if ((i + 1) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i + 1 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 100);
    class_test.Clear();
    std::cout <<  "------------------------------------------" << std::endl;
}

//PushFront
TEST_CASE("PushFront test", "[pushfront]") {

    std::cout << "PushFront test" << std::endl;

    List class_test;
    class_test.PushBack(100);//1 Р·РЅР°С‡РµРЅРёРµ

    for (unsigned long i = 0; i < 100; ++i) {

        class_test.PushFront(i);
        REQUIRE(class_test.Size() == i + 2);

        if ((i + 2) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i + 2 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 101);
    class_test.Clear();
    std::cout << "------------------------------------------" << std::endl;
}


//PopBack
TEST_CASE("PopBack test", "[popback]") {

    std::cout << "PopBack test" << std::endl;

    List class_test;

    for (int i = 0; i < 100; ++i) {
        class_test.PushBack(i);
    }
    std::cout << class_test.Size()  << std::endl;

   // CHECK(class_test.Size() == 100);

    for (int i = 100; i >= 1; --i) {

        class_test.PopBack();
        CHECK(class_test.Size() == i - 1);

        if ((i - 1) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i - 1 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 0);
    class_test.Clear();
    std::cout << "------------------------------------------" << std::endl;

    //РІРѕ РІСЂРµРјСЏ РІС‹С‡РёСЃР»РµРЅРёСЏ РІС‹СЂР°Р¶РµРЅРёСЏ Р±СѓРґРµС‚ СЃРіРµРЅРµСЂРёСЂРѕРІР°РЅРѕ РёСЃРєР»СЋС‡РµРЅРёРµ (Р»СЋР±РѕРіРѕ С‚РёРїР°).
    REQUIRE_THROWS(class_test.PopBack());
    //Р±СѓРґРµС‚ СЃРіРµРЅРµСЂРёСЂРѕРІР°РЅРѕ РёСЃРєР»СЋС‡РµРЅРёРµ, РєРѕС‚РѕСЂРѕРµ РїСЂРё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРё РІ СЃС‚СЂРѕРєСѓ Р±СѓРґРµС‚ 
    // СЃРѕРѕС‚РІРµС‚СЃС‚РІРѕРІР°С‚СЊ РїСЂРµРґРѕСЃС‚Р°РІР»РµРЅРЅРѕР№ СЃС‚СЂРѕРєРµ (СЃРїРµС†РёР°Р»СЊРЅРѕ РїРѕСЃС‚Р°РІРёР» РѕС‚Р»РёС‡РЅСѓСЋ СЃС‚СЂРѕРєСѓ)
    CHECK_THROWS_WITH(class_test.PopBack(), "list is not empty");
    //РћР¶РёРґР°РµС‚СЃСЏ, С‡С‚Рѕ РІРѕ РІСЂРµРјСЏ РІС‹С‡РёСЃР»РµРЅРёСЏ РІС‹СЂР°Р¶РµРЅРёСЏ РЅРµ Р±СѓРґРµС‚ РІС‹РґР°РЅРѕ РЅРёРєР°РєРёС… РёСЃРєР»СЋС‡РµРЅРёР№.
    REQUIRE_NOTHROW(class_test.PopBack());
}

//PopFront
TEST_CASE("PopFront test", "[PopFront]") {

    std::cout << "PopFront test" << std::endl;

    List class_test;

    for (int i = 0; i < 100; ++i) {
        class_test.PushBack(i);
    }
    std::cout << class_test.Size() << std::endl;


    for (int i = 100; i >= 1; --i) {

        class_test.PopFront();
        CHECK(class_test.Size() == i - 1);

        if ((i - 1) % 10 == 0) {
            std::cout << class_test.Size() << " = " << i - 1 << " << good!" << std::endl;
        }
    }

    CHECK(class_test.Size() == 0);
    class_test.Clear();

  
    std::cout << "------------------------------------------" << std::endl;

    //РІРѕ РІСЂРµРјСЏ РІС‹С‡РёСЃР»РµРЅРёСЏ РІС‹СЂР°Р¶РµРЅРёСЏ Р±СѓРґРµС‚ СЃРіРµРЅРµСЂРёСЂРѕРІР°РЅРѕ РёСЃРєР»СЋС‡РµРЅРёРµ (Р»СЋР±РѕРіРѕ С‚РёРїР°).
    REQUIRE_THROWS(class_test.PopFront());
    //Р±СѓРґРµС‚ СЃРіРµРЅРµСЂРёСЂРѕРІР°РЅРѕ РёСЃРєР»СЋС‡РµРЅРёРµ, РєРѕС‚РѕСЂРѕРµ РїСЂРё РїСЂРµРѕР±СЂР°Р·РѕРІР°РЅРёРё РІ СЃС‚СЂРѕРєСѓ Р±СѓРґРµС‚ 
    // СЃРѕРѕС‚РІРµС‚СЃС‚РІРѕРІР°С‚СЊ РїСЂРµРґРѕСЃС‚Р°РІР»РµРЅРЅРѕР№ СЃС‚СЂРѕРєРµ (СЃРїРµС†РёР°Р»СЊРЅРѕ РїРѕСЃС‚Р°РІРёР» РѕС‚Р»РёС‡РЅСѓСЋ СЃС‚СЂРѕРєСѓ)
    CHECK_THROWS_WITH(class_test.PopFront(), "list is not empty");
    //РћР¶РёРґР°РµС‚СЃСЏ, С‡С‚Рѕ РІРѕ РІСЂРµРјСЏ РІС‹С‡РёСЃР»РµРЅРёСЏ РІС‹СЂР°Р¶РµРЅРёСЏ РЅРµ Р±СѓРґРµС‚ РІС‹РґР°РЅРѕ РЅРёРєР°РєРёС… РёСЃРєР»СЋС‡РµРЅРёР№.
    REQUIRE_NOTHROW(class_test.PopFront());

}