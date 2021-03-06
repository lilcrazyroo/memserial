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

namespace memserial {
namespace detail {

/**
 *
 */
template< typename T >
struct SerialHelpers< T, is_primitive< T > > {
    using ValueType = T;

    /**
     *
     */
    static constexpr bool matchHash( uint32_t hash ) {

        return typeHash() == hash;
    }

    /**
     *
     */
    static constexpr uint32_t typeHash() {

        uint32_t type_hash = SERIAL_HASH_MAX;
        typeHash( type_hash );
        return type_hash;
    }

    static constexpr void typeHash( uint32_t& hash, std::size_t nesting = SERIAL_NESTING_MAX ) {

        hashCombine( hash, rebind_primitive< ValueType >::InternalIdent );
        hashCombine( hash, uint32_t( sizeof( ValueType ) ) );
    }

    /**
     *
     */
    static std::size_t byteSize( const ValueType& ) {

        return sizeof( ValueType );
    }

    /**
     *
     */
    template< typename Iterator >
    static void toBytes( const ValueType& value, Iterator&& begin, Iterator&& end ) {

        assert( std::ptrdiff_t( byteSize( value ) ) <= std::distance( begin, end ) );

        auto data_size = sizeof( ValueType );
        auto raw_data = reinterpret_cast< const char* >( &value );
        begin = std::copy_n( raw_data, data_size, begin );
    }

    /**
     *
     */
    template< typename Iterator >
    static void fromBytes( ValueType& value, Iterator&& begin, Iterator&& end ) {

        auto data_size = sizeof( ValueType );
        if ( std::ptrdiff_t( data_size ) > std::distance( begin, end ) )
            throw SerialException( SerialException::ExcOutOfRange );

        auto raw_data = reinterpret_cast< char* >( &value );
        std::copy_n( begin, data_size, raw_data );
        begin += data_size;
    }

    /**
     *
     */
    template< typename Stream >
    static void toDebug( const ValueType& value, Stream&& stream, uint8_t level ) {

        stream << +value;
    }
};

}} // --- namespace
