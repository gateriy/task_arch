п»ї//РїРѕРґРєР»СЋС‡Р°РµРј РјР°РєСЂРѕСЃС‹ catch2
#include <catch2/catch_test_macros.hpp>

#include <cstdint>

//РїСЂРѕРІРµСЂСЏРµРјР°СЏ С„СѓРЅРєС†РёСЏ
uint32_t factorial( uint32_t number ) {
    return number <= 1 ? number : factorial(number-1) * number;
}

//СЋРЅРёС‚-С‚РµСЃС‚
TEST_CASE( "Factorials are computed", "[factorial]" ) {
    REQUIRE( factorial( 1) == 1 );
    REQUIRE( factorial( 2) == 2 );
    REQUIRE( factorial( 3) == 6 );
    REQUIRE( factorial(10) == 3'628'800 );
}