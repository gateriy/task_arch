п»ї# CMakeList.txt: РїСЂРѕРµРєС‚ CMake РґР»СЏ Task_CMake_dll; РІРєР»СЋС‡РёС‚Рµ РёСЃС…РѕРґРЅС‹Р№ РєРѕРґ Рё РѕРїСЂРµРґРµР»РµРЅРёСЏ,
# СѓРєР°Р¶РёС‚Рµ Р·РґРµСЃСЊ Р»РѕРіРёРєСѓ РґР»СЏ РєРѕРЅРєСЂРµС‚РЅРѕРіРѕ РїСЂРѕРµРєС‚Р°.
#
cmake_minimum_required (VERSION 3.8)

# Р’РєР»СЋС‡РµРЅРёРµ РіРѕСЂСЏС‡РµР№ РїРµСЂРµР·Р°РіСЂСѓР·РєРё РґР»СЏ РєРѕРјРїРёР»СЏС‚РѕСЂРѕРІ MSVC, РµСЃР»Рё РїРѕРґРґРµСЂР¶РёРІР°РµС‚СЃСЏ.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("Task_CMake_dll")

# Р”РѕР±Р°РІСЊС‚Рµ РёСЃС‚РѕС‡РЅРёРє РІ РёСЃРїРѕР»РЅСЏРµРјС‹Р№ С„Р°Р№Р» СЌС‚РѕРіРѕ РїСЂРѕРµРєС‚Р°.
add_executable (Task_CMake_dll "Task_CMake_dll.cpp"   "AllConfigTask.cpp" "AllConfigTask.h" "Task_1.cpp" "Task_1.h" "Task_2.cpp" "Task_2.h" "Task_3.cpp" "Task_3.h")

add_library(Task_static STATIC "Task_static.cpp" "Task_static.h")
set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(Task_dll SHARED "Task_dll.cpp" "Task_dll.h")
target_link_libraries(Task_CMake_dll Task_dll Task_static)


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Task_CMake_dll PROPERTY CXX_STANDARD 20)
endif()

# TODO: Р”РѕР±Р°РІСЊС‚Рµ С‚РµСЃС‚С‹ Рё С†РµР»РµРІС‹Рµ РѕР±СЉРµРєС‚С‹, РµСЃР»Рё СЌС‚Рѕ РЅРµРѕР±С…РѕРґРёРјРѕ.
