// Copyright 2019 Ilya Kiselev.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include <string>

namespace memserial {

/**
 * \~english
 * \brief Returns the current version of serialization methods and serializable types.
 * \return Version number.
 * \~russian
 * \brief Возвращает актуальную версию методов сериализации и сериализуемых типов.
 * \return Номер версии.
 */
uint64_t serialVersion();

/**
 * \~english
 * \brief Checks the version relevance of serialization methods and serializable types for current build.
 * \return Sign of relevance.
 * \~russian
 * \brief Проверяет актуальность версии методов сериализации и сериализуемых типов для текущей сборки.
 * \return Признак актуальности.
 */
bool checkVersion();

/**
 * \~english
 * \brief Checks the version relevance of serializable type for current build.
 * \return Sign of relevance.
 * \~russian
 * \brief Проверяет актуальность версии сериализуемого типа для текущей сборки.
 * \return Признак актуальности.
 */
template< typename T >
bool checkVersion();

/**
 * \~english
 * \brief Returns structured data in serialized form.
 * \param value Original data structure.
 * \return Byte sequence represented by the original structure.
 * \~russian
 * \brief Возвращает структуру данных в сериализованном виде.
 * \param value Исходная структура данных.
 * \return Последовательность байт, представленная исходной структурой.
 */
template< typename ByteArray = std::string, typename T >
ByteArray serialize( const T& value );

/**
 * \~english
 * \brief Returns serialized data in structured form.
 * \param bytes Byte sequence.
 * \return Original data structure recovered from a set of bytes.
 * \throw SerialException In case of invalid data.
 * \~russian
 * \brief Возвращает сериализованные данные в структурированном виде.
 * \param bytes Последовательность байт.
 * \return Исходная структура данных, восстановленная из набора байт.
 * \throw SerialException В случае некорректных данных.
 */
template< typename T, typename ByteArray >
T parse( const ByteArray& bytes );

/**
 * \~english
 * \brief Returns identifier of a serializable type.
 * \return Type identifier.
 * \~russian
 * \brief Возвращает идентификатор сериализуемого типа.
 * \return Идентификатор типа.
 */
template< typename T >
uint64_t ident();

/**
 * \~english
 * \brief Returns identifier of a type by its string name.
 * \param alias Type string name.
 * \return Type identifier or -1 if the name is not found.
 * \~russian
 * \brief Возвращает идентификатор типа по его строковому имени.
 * \param alias Строковое имя типа.
 * \return Идентификатор типа или -1, если имя не найдено.
 */
template< typename ByteArray >
uint64_t ident( const ByteArray& alias );

/**
 * \~english
 * \brief Returns name of a serializable type.
 * \return Type string name.
 * \~russian
 * \brief Возвращает имя сериализуемого типа.
 * \return Строковое имя типа.
 */
template< typename T, typename ByteArray = std::string >
ByteArray alias();

/**
 * \~english
 * \brief Returns the name of a type by its identifier.
 * \param ident Type identifier.
 * \return Type string name or empty string if identifier is not found.
 * \~russian
 * \brief Возвращает имя типа по его идентификатору.
 * \param ident Идентификатор типа.
 * \return Строковое имя типа или пустая строка, если идентификатор не найден.
 */
template< typename ByteArray = std::string >
ByteArray alias( uint64_t ident );

/**
 * \~english
 * \brief Prints structured data in human-readable format.
 * \param stream Class object for streaming output.
 * \param value Original data structure.
 * \~russian
 * \brief Печатает структуру данных в человекочитаемом формате.
 * \param stream Объект класса для потокового вывода.
 * \param value Исходная структура данных.
 */
template< typename Stream, typename T >
void print( Stream&& stream, const T& value );

/**
 * \~english
 * \brief Prints serialized data in human-readable format.
 * \param stream Class object for streaming output.
 * \param bytes Byte sequence.
 * \~russian
 * \brief Печатает сериализованные данные в человекочитаемом формате.
 * \param stream Объект класса для потокового вывода.
 * \param bytes Последовательность байт.
 */
template< typename Stream, typename ByteArray >
void trace( Stream&& stream, const ByteArray& bytes );

} // --- namespace
