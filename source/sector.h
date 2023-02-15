// Copyright (c) Veeam Software Group GmbH

#pragma once

static __inline unsigned int sector_to_uint( sector_t sect )
{
    return (unsigned int)(sect << SECTOR_SHIFT);
}

static __inline size_t sector_to_size( sector_t sect )
{
    return (size_t)(sect << SECTOR_SHIFT);
}

static __inline stream_size_t sector_to_streamsize( sector_t sect )
{
    return (stream_size_t)(sect) << (stream_size_t)(SECTOR_SHIFT);
}

static __inline sector_t sector_from_uint( unsigned int size )
{
    return (sector_t)(size >> SECTOR_SHIFT);
}

static __inline sector_t sector_from_size( size_t size )
{
    return (sector_t)(size >> SECTOR_SHIFT);
}

static __inline sector_t sector_from_streamsize( stream_size_t steamsize )
{
    return (sector_t)(steamsize >> SECTOR_SHIFT);
}

#ifndef sector_div
#define sector_div(a, b) do_div(a, b)
#endif

#define sector_div_up(n, sz) ( \
{ \
	sector_t _r = ((n) + (sz) - 1); \
	sector_div(_r, (sz)); \
	_r; \
} \
)
