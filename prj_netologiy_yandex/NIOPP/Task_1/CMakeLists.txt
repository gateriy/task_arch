п»ї# CMakeList.txt: РїСЂРѕРµРєС‚ CMake РґР»СЏ Task_1; РІРєР»СЋС‡РёС‚Рµ РёСЃС…РѕРґРЅС‹Р№ РєРѕРґ Рё РѕРїСЂРµРґРµР»РµРЅРёСЏ,
# СѓРєР°Р¶РёС‚Рµ Р·РґРµСЃСЊ Р»РѕРіРёРєСѓ РґР»СЏ РєРѕРЅРєСЂРµС‚РЅРѕРіРѕ РїСЂРѕРµРєС‚Р°.
#
cmake_minimum_required (VERSION 3.8)

# Р’РєР»СЋС‡РµРЅРёРµ РіРѕСЂСЏС‡РµР№ РїРµСЂРµР·Р°РіСЂСѓР·РєРё РґР»СЏ РєРѕРјРїРёР»СЏС‚РѕСЂРѕРІ MSVC, РµСЃР»Рё РїРѕРґРґРµСЂР¶РёРІР°РµС‚СЃСЏ.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Task_1")

# Р”РѕР±Р°РІСЊС‚Рµ РёСЃС‚РѕС‡РЅРёРє РІ РёСЃРїРѕР»РЅСЏРµРјС‹Р№ С„Р°Р№Р» СЌС‚РѕРіРѕ РїСЂРѕРµРєС‚Р°.
add_executable (Task_1 "Task_1.cpp" "Task_1.h" "Config.h" "Config.cpp" "Block_1.h" "Block_1.cpp" "Block_2.h" "Block_2.cpp" "Block_3.h" "Block_3.cpp" "Block_4.h" "Block_4.cpp" "Block_5.h" "Block_5.cpp")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Task_1 PROPERTY CXX_STANDARD 20)
endif()

# TODO: Р”РѕР±Р°РІСЊС‚Рµ С‚РµСЃС‚С‹ Рё С†РµР»РµРІС‹Рµ РѕР±СЉРµРєС‚С‹, РµСЃР»Рё СЌС‚Рѕ РЅРµРѕР±С…РѕРґРёРјРѕ.
