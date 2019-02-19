cmake_minimum_required(VERSION 2.8) #Проверка версии CMake.

set(PROJECT_NAME All-labs) #Создаем обычную локальную переменную с именем проекта
project(${PROJECT_NAME}) # Название проекта

set(Vector Vector) #Переменная с именем библиотеки
set(VectorLib VectorLib) #Переменная с именем библиотеки
set(VectorTest VectorTest) #Переменная с именем библиотеки

set(Stack Stack) #Переменная с именем библиотеки
set(StackLib StackLib) #Переменная с именем библиотеки
set(StackTest StackTest) #Переменная с именем библиотеки

set(Queue Queue) #Переменная с именем библиотеки
set(QueueLib QueueLib) #Переменная с именем библиотеки
set(QueueTest QueueTest) #Переменная с именем библиотеки

set(List List) #Переменная с именем библиотеки
set(ListLib ListLib) #Переменная с именем библиотеки
set(ListTest ListTest) #Переменная с именем библиотеки

set(ArrList ArrList) #Переменная с именем библиотеки
set(ArrListLib ArrListLib) #Переменная с именем библиотеки
set(ArrListTest ArrListTest) #Переменная с именем библиотеки

set(MultiStack MultiStack) #Переменная с именем библиотеки
set(MultiStackLib MultiStackLib) #Переменная с именем библиотеки
set(MultiStackTest MultiStackTest) #Переменная с именем библиотеки

set(Polinom Polinom) #Переменная с именем библиотеки
set(PolinomLib PolinomLib) #Переменная с именем библиотеки
set(PolinomTest PolinomTest) #Переменная с именем библиотеки

set(StackList StackList) #Переменная с именем библиотеки
set(StackListLib StackListLib) #Переменная с именем библиотеки
set(StackListTest StackListTest) #Переменная с именем библиотеки

set(Polish Polish) #Переменная с именем библиотеки
set(PolishLib PolishLib) #Переменная с именем библиотеки
set(PolishTest PolishTest) #Переменная с именем библиотеки

set(CMAKE_CONFIGURATION_TYPES "Debug;Release" CACHE STRING "Configs" FORCE) #Создается переменная CMAKE_CONFIGURATION_TYPES со значением "Debug;Release" и меткой/разделом Configs, переменная сохраниется в специальном файле доступном из всех файлов,
if(NOT CMAKE_BUILD_TYPE) # проверка имеющихся у компилятора вариантов сборки
  set(CMAKE_BUILD_TYPE Release) #Если нет то устанавливаем Release
endif()

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/VectorLib ${CMAKE_CURRENT_SOURCE_DIR}/gtest)

add_subdirectory(Vector)
add_subdirectory(VectorLib)
add_subdirectory(VectorTest)
add_subdirectory(gtest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackLib)
add_subdirectory(Stack)
add_subdirectory(StackLib)
add_subdirectory(StackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/QueueLib)
add_subdirectory(Queue)
add_subdirectory(QueueLib)
add_subdirectory(QueueTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ListLib)
add_subdirectory(List)
add_subdirectory(ListLib)
add_subdirectory(ListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/ArrListLib)
add_subdirectory(ArrList)
add_subdirectory(ArrListLib)
add_subdirectory(ArrListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/MultiStackLib)
add_subdirectory(MultiStack)
add_subdirectory(MultiStackLib)
add_subdirectory(MultiStackTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolinomLib)
add_subdirectory(Polinom)
add_subdirectory(PolinomLib)
add_subdirectory(PolinomTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/StackListLib)
add_subdirectory(StackList)
add_subdirectory(StackListLib)
add_subdirectory(StackListTest)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/PolishLib)
add_subdirectory(Polish)
add_subdirectory(PolishLib)
add_subdirectory(PolishTest)

#file(GLOB hdrs "*.h*") #Добавляем в переменную hdrs все файлы с расширением .h
#file(GLOB srcs "*.cpp") #Добавляем в переменную srcs все файлы с расширением .h


#add_executable(${PROJECT_NAME} ${srcs} ${hdrs}) #Создаем проект с именем из переменной ${PROJECT_NAME}, в него добавляются файлы из переменных ${srcs} и ${hdrs}

#add_subdirectory(lib1) #Собираем проект в поддиректории lib1
#target_link_libraries(${PROJECT_NAME} ${MyLib1}) #Подключаем к проекту с именем ${PROJECT_NAME} библиотеку с именем ${MyLib1}