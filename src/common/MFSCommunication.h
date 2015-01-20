/*
   Copyright 2005-2010 Jakub Kruszona-Zawadzki, Gemius SA, 2013 Skytechnology sp. z o.o..

   This file was part of MooseFS and is part of LizardFS.

   LizardFS is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, version 3.

   LizardFS is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with LizardFS  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

// all data field transfered in network order.
// packet structure:
// type:32 length:32 data:lengthB
//

#ifndef PROTO_BASE
#  include "common/platform.h"
#endif

#define MFSBLOCKSINCHUNK 0x400
#if LIGHT_MFS == 1
#  define MFSSIGNATURE "LFS"
#  define MFSCHUNKSIZE 0x00400000
#  define MFSCHUNKMASK 0x003FFFFF
#  define MFSCHUNKBITS 22
#  define MFSCHUNKBLOCKMASK 0x003FF000
#  define MFSBLOCKSIZE 0x1000
#  define MFSBLOCKMASK 0x0FFF
#  define MFSBLOCKNEGMASK 0x7FFFF000
#  define MFSBLOCKBITS 12
#  define MFSCRCEMPTY 0xC71C0011U
#  define MFSHDRSIZE 0x1080
#else
#  define MFSSIGNATURE "MFS"
#  define MFSCHUNKSIZE 0x04000000
#  define MFSCHUNKMASK 0x03FFFFFF
#  define MFSCHUNKBITS 26
#  define MFSCHUNKBLOCKMASK 0x03FF0000
#  define MFSBLOCKSIZE 0x10000
#  define MFSBLOCKMASK 0x0FFFF
#  define MFSBLOCKNEGMASK 0x7FFF0000
#  define MFSBLOCKBITS 16
#  define MFSCRCEMPTY 0xD7978EEBU
#  define MFSHDRSIZE 0x1400
#endif

//UNIVERSAL
#define VERSION_ANY 0

#define CRC_POLY 0xEDB88320U

#define MFS_ROOT_ID 1

#define MFS_NAME_MAX 255
#define MFS_MAX_FILE_SIZE (((uint64_t)(MFSCHUNKSIZE))<<31)

#define MFS_INODE_REUSE_DELAY 86400

/// field values: status
#define STATUS_OK                      0    // OK
#define ERROR_EPERM                    1    // Operation not permitted
#define ERROR_ENOTDIR                  2    // Not a directory
#define ERROR_ENOENT                   3    // No such file or directory
#define ERROR_EACCES                   4    // Permission denied
#define ERROR_EEXIST                   5    // File exists
#define ERROR_EINVAL                   6    // Invalid argument
#define ERROR_ENOTEMPTY                7    // Directory not empty
#define ERROR_CHUNKLOST                8    // Chunk lost
#define ERROR_OUTOFMEMORY              9    // Out of memory
#define ERROR_INDEXTOOBIG             10    // Index too big
#define ERROR_LOCKED                  11    // Chunk locked
#define ERROR_NOCHUNKSERVERS          12    // No chunk servers
#define ERROR_NOCHUNK                 13    // No such chunk
#define ERROR_CHUNKBUSY               14    // Chunk is busy
#define ERROR_REGISTER                15    // Incorrect register BLOB
#define ERROR_NOTDONE                 16    // None of chunk servers performed requested operation
#define ERROR_NOTOPENED               17    // File not opened
#define ERROR_NOTSTARTED              18    // Write not started
#define ERROR_WRONGVERSION            19    // Wrong chunk version
#define ERROR_CHUNKEXIST              20    // Chunk already exists
#define ERROR_NOSPACE                 21    // No space left
#define ERROR_IO                      22    // IO error
#define ERROR_BNUMTOOBIG              23    // Incorrect block number
#define ERROR_WRONGSIZE               24    // Incorrect size
#define ERROR_WRONGOFFSET             25    // Incorrect offset
#define ERROR_CANTCONNECT             26    // Can't connect
#define ERROR_WRONGCHUNKID            27    // Incorrect chunk id
#define ERROR_DISCONNECTED            28    // Disconnected
#define ERROR_CRC                     29    // CRC error
#define ERROR_DELAYED                 30    // Operation delayed
#define ERROR_CANTCREATEPATH          31    // Can't create path
#define ERROR_MISMATCH                32    // Data mismatch
#define ERROR_EROFS                   33    // Read-only file system
#define ERROR_QUOTA                   34    // Quota exceeded
#define ERROR_BADSESSIONID            35    // Bad session id
#define ERROR_NOPASSWORD              36    // Password is needed
#define ERROR_BADPASSWORD             37    // Incorrect password
#define ERROR_ENOATTR                 38    // Attribute not found
#define ERROR_ENOTSUP                 39    // Operation not supported
#define ERROR_ERANGE                  40    // Result too large
#define ERROR_TIMEOUT                 41    // Timeout
#define ERROR_BADMETADATACHECKSUM     42    // Metadata checksum not matching
#define ERROR_CHANGELOGINCONSISTENT   43    // Changelog inconsistent
#define ERROR_PARSE                   44    // Parsing unsuccessful
#define ERROR_METADATAVERSIONMISMATCH 45    // Metadata version mismatch
#define ERROR_NOTLOCKED               46    // No such lock
#define ERROR_WRONGLOCKID             47    // Wrong lock id
#define ERROR_NOTPOSSIBLE             48    // It's not possible to perform operation in this way
#define ERROR_TEMP_NOTPOSSIBLE        49    // Operation temporarily not possible
#define ERROR_RESERVED3               50
#define ERROR_RESERVED4               51

#define ERROR_MAX                     52

#define ERROR_STRINGS \
	"OK", \
	"Operation not permitted", \
	"Not a directory", \
	"No such file or directory", \
	"Permission denied", \
	"File exists", \
	"Invalid argument", \
	"Directory not empty", \
	"Chunk lost", \
	"Out of memory", \
	"Index too big", \
	"Chunk locked", \
	"No chunk servers", \
	"No such chunk", \
	"Chunk is busy", \
	"Incorrect register BLOB", \
	"None of chunk servers performed requested operation", \
	"File not opened", \
	"Write not started", \
	"Wrong chunk version", \
	"Chunk already exists", \
	"No space left", \
	"IO error", \
	"Incorrect block number", \
	"Incorrect size", \
	"Incorrect offset", \
	"Can't connect", \
	"Incorrect chunk id", \
	"Disconnected", \
	"CRC error", \
	"Operation delayed", \
	"Can't create path", \
	"Data mismatch", \
	"Read-only file system", \
	"Quota exceeded", \
	"Bad session id", \
	"Password is needed", \
	"Incorrect password", \
	"Attribute not found", \
	"Operation not supported", \
	"Result too large", \
	"Timeout", \
	"Metadata checksum not matching", \
	"Changelog inconsistent", \
	"Parsing unsuccessful", \
	"Metadata version mismatch", \
	"No such lock", \
	"Wrong lock id", \
	"Operation not possible", \
	"Operation temporarily not possible", \
	"Unknown MFS error", \
	"Unknown MFS error", \
	"Unknown MFS error"

/// field values: nodetype
#define TYPE_FILE             'f'
#define TYPE_DIRECTORY        'd'
#define TYPE_SYMLINK          'l'
#define TYPE_FIFO             'q'
#define TYPE_BLOCKDEV         'b'
#define TYPE_CHARDEV          'c'
#define TYPE_SOCKET           's'

// 't' and 'r' are only for internal master use - they are in readdir shown as 'f'
#define TYPE_TRASH            't'
#define TYPE_RESERVED         'r'
#define TYPE_UNKNOWN          '?'

// mode mask:  "modemask" field in "CLTOMA_FUSE_ACCESS"
#define MODE_MASK_R            4
#define MODE_MASK_W            2
#define MODE_MASK_X            1
#define MODE_MASK_EMPTY        0 // Just to avoid '0' argument when passing an empty mask

// flags: "setmask" field in "CLTOMA_FUSE_SETATTR"
#define SET_MODE_FLAG          0x0002
#define SET_UID_FLAG           0x0004
#define SET_GID_FLAG           0x0008
#define SET_MTIME_NOW_FLAG     0x0010
#define SET_MTIME_FLAG         0x0020
#define SET_ATIME_FLAG         0x0040
#define SET_ATIME_NOW_FLAG     0x0080

// dtypes:
#define DTYPE_UNKNOWN          0
#define DTYPE_TRASH            1
#define DTYPE_RESERVED         2
#define DTYPE_ISVALID(x)       (((uint32_t)(x))<=2)

/// field values: smode
#define SMODE_SET              0
#define SMODE_INCREASE         1
#define SMODE_DECREASE         2
#define SMODE_RSET             4
#define SMODE_RINCREASE        5
#define SMODE_RDECREASE        6

#define SMODE_TMASK            3
#define SMODE_RMASK            4
#define SMODE_ISVALID(x)       (((x)&SMODE_TMASK)!=3 && ((uint32_t)(x))<=7)

/// field values: gmode
#define GMODE_NORMAL           0
#define GMODE_RECURSIVE        1

#define GMODE_ISVALID(x)       (((uint32_t)(x))<=1)

/// field values: matrixid
#define MATRIX_ALL_COPIES      0
#define MATRIX_REGULAR_COPIES  1

// size of the matrix of chunks in the CGI interface = 11 x 11
#define CHUNK_MATRIX_SIZE      11

// extraattr:
#define EATTR_NOOWNER          0x01
#define EATTR_NOACACHE         0x02
#define EATTR_NOECACHE         0x04
#define EATTR_NODATACACHE      0x08

#define EATTR_BITS             4

#define EATTR_STRINGS \
	"noowner", \
	"noattrcache", \
	"noentrycache", \
	"nodatacache"

#define EATTR_DESCRIPTIONS \
	"every user (except root) sees object as his (her) own", \
	"prevent standard object attributes from being stored in kernel cache", \
	"prevent directory entries from being stored in kernel cache", \
	"prevent file data from being kept in kernel cache"

// mode attr (higher 4 bits of mode in node attr)
#define MATTR_NOACACHE         0x01
#define MATTR_NOECACHE         0x02
#define MATTR_ALLOWDATACACHE   0x04
#define MATTR_UNDEFINED        0x08

// getdir:
#define GETDIR_FLAG_WITHATTR   0x01
#define GETDIR_FLAG_ADDTOCACHE 0x02

// register sesflags:
#define SESFLAG_READONLY          0x01  // meaning is obvious
#define SESFLAG_DYNAMICIP         0x02  // sessionid can be used by any IP - dangerous for high privileged sessions - one could connect from different computer using stolen session id
#define SESFLAG_IGNOREGID         0x04  // gid is ignored during access testing (when user id is different from object's uid then or'ed 'group' and 'other' rights are used)
#define SESFLAG_ALLCANCHANGEQUOTA 0x08  // quota can be modified also by a non-root user
#define SESFLAG_MAPALL            0x10  // all users (except root) are mapped to specific uid and gid
#define SESFLAG_NOMASTERPERMCHECK 0x20  // disable permission checks in master server
#define SESFLAG_NONROOTMETA       0x40  // allow non-root users to use filesystem mounted in the meta mode

#define SESFLAG_POS_STRINGS \
	"read-only", \
	"not_restricted_ip", \
	"ignore_gid", \
	"all_can_change_quota", \
	"map_all", \
	"no_master_permission_check", \
	"available_for_non_root_users", \
	"undefined_flag_7"

#define SESFLAG_NEG_STRINGS \
	"read-write", \
	"restricted_ip", \
	NULL, \
	NULL, \
	NULL, \
	NULL, \
	NULL, \
	NULL

#ifdef LIZARDFS_WIRESHARK_PLUGIN
/// field values: sugidclearmode
#define SUGIDCLEAR_NEVER 0
#define SUGIDCLEAR_ALWAYS 1
#define SUGIDCLEAR_OSX 2
#define SUGIDCLEAR_BSD 3
#define SUGIDCLEAR_EXT 4
#define SUGIDCLEAR_XFS 5
// end of sugidclearmode values
#else
enum class SugidClearMode {
	kNever = 0,
	kAlways = 1,
	kOsx = 2,
	kBsd = 3,
	kExt = 4,
	kXfs = 5
};
#endif

#define SUGID_CLEAR_MODE_OPTIONS 6

#define SUGID_CLEAR_MODE_STRINGS \
	"never", \
	"always", \
	"osx", \
	"bsd", \
	"ext", \
	"xfs"


// flags: "flags" fileld in "CLTOMA_FUSE_AQUIRE"
#define WANT_READ 1
#define WANT_WRITE 2
#define AFTER_CREATE 4

/// field values: xattrsmode
#define XATTR_SMODE_CREATE_OR_REPLACE 0
#define XATTR_SMODE_CREATE_ONLY       1
#define XATTR_SMODE_REPLACE_ONLY      2
#define XATTR_SMODE_REMOVE            3

/// field values: xattrgmode
#define XATTR_GMODE_GET_DATA   0
#define XATTR_GMODE_LENGTH_ONLY 1

// MFS uses Linux limits
#define MFS_XATTR_NAME_MAX 255
#define MFS_XATTR_SIZE_MAX 65536
#define MFS_XATTR_LIST_MAX 65536

/// field values: serverstatus
#define LIZ_METADATASERVER_STATUS_MASTER 1
#define LIZ_METADATASERVER_STATUS_SHADOW_CONNECTED 2
#define LIZ_METADATASERVER_STATUS_SHADOW_DISCONNECTED 3

// Metalogger specific messages.

/// field values: filenum
#define DOWNLOAD_METADATA_MFS 1
#define DOWNLOAD_CHANGELOG_MFS 11
#define DOWNLOAD_CHANGELOG_MFS_1 12
#define DOWNLOAD_SESSIONS_MFS 2

#define FORCE_LOG_ROTATE 0x55

// ANY <-> ANY

#define ANTOAN_NOP 0
/// -
/// msgid:32 // only in communication from master to client

// these packets are acceptable since version 1.6.27 (but treated as NOP in this version)
#define ANTOAN_UNKNOWN_COMMAND 1
/// cmdno:32 size:32 vershex:32
/// msgid:32 cmdno:32 size:32 vershex:32 // only in communication from master to client

#define ANTOAN_BAD_COMMAND_SIZE 2
/// cmdno:32 size:32 vershex:32
/// msgid:32 cmdno:32 size:32 vershex:32 // only in communication from master to client

// METALOGGER <-> MASTER

// 0x0032
#define MLTOMA_REGISTER (PROTO_BASE+50)
/// rver==1:8 vershex:32 timeout:16
/// rver==2:8 vershex:32 timeout:16 minversion:64
/// rver==3:8 vershex:32 timeout:16
/// rver==4:8 vershex:32 timeout:16 minversion:64

// 0x0033
#define MATOML_METACHANGES_LOG (PROTO_BASE+51)
/// rver==0xFF:8 logversion:64 logdata:STRING
/// rver==0x55:8 // LOG_ROTATE

// 0x041C
#define LIZ_MATOML_END_SESSION (1000U + 52)
/// -

// 0x003C
#define MLTOMA_DOWNLOAD_START (PROTO_BASE+60)
/// filenum:8

// 0x003D
#define MATOML_DOWNLOAD_START (PROTO_BASE+61)
/// status:8
/// leng:64

// 0x003E
#define MLTOMA_DOWNLOAD_DATA (PROTO_BASE+62)
/// offset:64 leng:32

// 0x003F
#define MATOML_DOWNLOAD_DATA (PROTO_BASE+63)
/// offset:64 leng:32 crc:32 data:BYTES[leng]

// 0x0040
#define MLTOMA_DOWNLOAD_END (PROTO_BASE+64)
/// -

// 0x0429
#define LIZ_MLTOMA_REGISTER_SHADOW (1000U + 65)
/// version==0 vershex:32 timeout:32 metadataversion:64

// 0x042A
#define LIZ_MATOML_REGISTER_SHADOW (1000U + 66)
/// version==0 status:8
/// version==1 vershex:32 metadataversion:64

// 0x42B
#define LIZ_MLTOMA_CHANGELOG_APPLY_ERROR (1000U + 67)
/// status:8

// 0x42C
#define LIZ_MATOML_CHANGELOG_APPLY_ERROR (1000U + 68)
/// status:8

// 0x42D
#define LIZ_MLTOMA_CLTOMA_PORT (1000U + 69)
/// port:16

// CHUNKSERVER <-> MASTER

// 0x0064
#define CSTOMA_REGISTER (PROTO_BASE+100)
// - version 0:
// myip:32 myport:16 usedspace:64 totalspace:64 N*[ chunkid:64 version:32 ]
// - version 1-4:
/// rver==1:8 myip:32 myport:16 usedspace:64 totalspace:64 tdusedspace:64 tdtotalspace:64 tdchunks:32 chunks:(N * [chunkid:64 version:32])
/// rver==2:8 myip:32 myport:16 usedspace:64 totalspace:64 chunkcount:32 tdusedspace:64 tdtotalspace:64 tdchunks:32 chunks:(N * [chunkid:64 version:32])
/// rver==3:8 myip:32 myport:16 tpctimeout:16 usedspace:64 totalspace:64 chunkcount:32 tdusedspace:64 tdtotalspace:64 tdchunks:32 chunks:(N * [chunkid:64 version:32])
/// rver==4:8 version:32 myip:32 myport:16 tcptimeout:16 usedspace:64 totalspace:64 chunkcount:32 tdusedspace:64 tdtotalspace:64 tdchunks:32 chunks:(N * [chunkid:64 version:32])
// version 5:
/// rver==50:8 version:32 myip:32 myport:16 tcptimeout:16   // version 5 / BEGIN
/// rver==51:8 chunks:(N * [chunkid:64 version:32])          // version 5 / CHUNKS
/// rver==52:8 usedspace:64 totalspace:64 chunkcount:32 tdusedspace:64 tdtotalspace:64 tdchunks:32 // version 5 / END

// 0x044C
#define LIZ_CSTOMA_REGISTER_HOST (1000U + 100U)
/// ip:32 port:16 timeout:32 vershex:32

// 0x044D
#define LIZ_CSTOMA_REGISTER_CHUNKS (1000U + 101U)
/// chunks:(N * [chunkid:64 chunkversion:32])

// 0x044E
#define LIZ_CSTOMA_REGISTER_SPACE (1000U + 102U)
/// usedspace:64 totalspace:64 chunkcount:32 tdusedspace:64 tdtotalspace:64 tdchunkcount:32

// 0x044F
#define LIZ_CSTOMA_REGISTER_LABEL (1000U + 103U)
/// label:STDSTRING

// 0x0065
#define CSTOMA_SPACE (PROTO_BASE+101)
/// usedspace:64 totalspace:64
/// usedspace:64 totalspace:64 tdusedspace:64 tdtotalspace:64
/// usedspace:64 totalspace:64 chunkcount:32 tdusedspace:64 tdtotalspace:64 tdchunkcount:32

// 0x0066
#define CSTOMA_CHUNK_DAMAGED (PROTO_BASE+102)
/// chunks:(N * [chunkid:64])

// 0x0067
// #define MATOCS_STRUCTURE_LOG (PROTO_BASE+103)
// version:32 logdata:string (N*[ char:8 ])
// 0xFF:8 version:64 logdata:string (N*[ char:8 ])

// 0x0068
// #define MATOCS_STRUCTURE_LOG_ROTATE (PROTO_BASE+104)
// -

// 0x0069
#define CSTOMA_CHUNK_LOST (PROTO_BASE+105)
/// chunks:(N * [chunkid:64])

// 0x006A
#define CSTOMA_ERROR_OCCURRED (PROTO_BASE+106)
/// -

// 0x006B
#define CSTOMA_CHUNK_NEW (PROTO_BASE+107)
/// chunks:(N * [chunkid:64 chunkversion:32])

// 0x006E
#define MATOCS_CREATE (PROTO_BASE+110)
/// chunkid:64 chunkversion:32

// 0x006F
#define CSTOMA_CREATE (PROTO_BASE+111)
/// chunkid:64 status:8

// 0x0078
#define MATOCS_DELETE (PROTO_BASE+120)
/// chunkid:64 chunkversion:32

// 0x0079
#define CSTOMA_DELETE (PROTO_BASE+121)
/// chunkid:64 status:8

// 0x0082
#define MATOCS_DUPLICATE (PROTO_BASE+130)
/// chunkid:64 chunkversion:32 oldchunkid:64 oldchunkversion:32

// 0x0083
#define CSTOMA_DUPLICATE (PROTO_BASE+131)
/// chunkid:64 status:8

// 0x008C
#define MATOCS_SET_VERSION (PROTO_BASE + 140)
/// chunkid:64 chunkversion:32 oldchunkversion:32

// 0x008D
#define CSTOMA_SET_VERSION (PROTO_BASE + 141)
/// chunkid:64 status:8

// 0x0096
#define MATOCS_REPLICATE (PROTO_BASE+150)
/// chunkid:64 chunkversion:32 ip:32 port:16

// 0x0097
#define CSTOMA_REPLICATE (PROTO_BASE+151)
/// chunkid:64 chunkversion:32 status:8

// 0x0098
#define MATOCS_CHUNKOP (PROTO_BASE+152)
/// chunkid:64 chunkversion:32 newchunkversion:32 copychunkid:64 copychunkversion:32 chunklength:32
// all chunk operations
// newchunkversion>0 && chunklength==0xFFFFFFFF && copychunkid==0              -> change version
// newchunkversion>0 && chunklength==0xFFFFFFFF && copycnunkid>0               -> duplicate
// newchunkversion>0 && chunklength>=0 && chunklength<=MFSCHUNKSIZE && copychunkid==0 -> truncate
// newchunkversion>0 && chunklength>=0 && chunklength<=MFSCHUNKSIZE && copychunkid>0  -> duplicate and truncate
// newchunkversion==0 && chunklength==0                                        -> delete
// newchunkversion==0 && chunklength==1                                        -> create
// newchunkversion==0 && chunklength==2                                        -> test

// 0x0099
#define CSTOMA_CHUNKOP (PROTO_BASE+153)
/// chunkid:64 chunkversion:32 newchunkversion:32 copychunkid:64 copychunkversion:32 chunklength:32 status:8

// 0x00A0
#define MATOCS_TRUNCATE (PROTO_BASE+160)
/// chunkid:64 chunklength:32 chunkversion:32 oldchunkversion:32

// 0x00A1
#define CSTOMA_TRUNCATE (PROTO_BASE+161)
/// chunkid:64 status:8

// 0x00AA
#define MATOCS_DUPTRUNC (PROTO_BASE+170)
/// chunkid:64 chunkversion:32 oldchunkid:64 oldchunkversion:32 chunklength:32

// 0x00AB
#define CSTOMA_DUPTRUNC (PROTO_BASE+171)
/// chunkid:64 status:8

// CHUNKSERVER <-> CLIENT/CHUNKSERVER

// 0x00C8
#define CLTOCS_READ (PROTO_BASE+200)
/// chunkid:64 chunkversion:32 offset:32 size:32

// 0x00C9
#define CSTOCL_READ_STATUS (PROTO_BASE+201)
/// chunkid:64 status:8

// 0x00CA
#define CSTOCL_READ_DATA (PROTO_BASE+202)
/// chunkid:64 offset:32 size:32 crc:32 data:BYTES[size]

// 0x00D2
#define CLTOCS_WRITE (PROTO_BASE+210)
/// chunkid:64 chunkversion:32 chain:(N * [ip:32 port:16])

// 0x00D3
#define CSTOCL_WRITE_STATUS (PROTO_BASE+211)
/// chunkid:64 writeid:32 status:8

// 0x00D4
#define CLTOCS_WRITE_DATA (PROTO_BASE+212)
/// chunkid:64 writeid:32 blocknum:16 offset:16 size:32 crc:32 data:BYTES[size]

// 0x00D5
#define CLTOCS_WRITE_FINISH (PROTO_BASE+213)
/// chunkid:64 chunkversion:32

//CHUNKSERVER <-> CHUNKSERVER

// 0x00FA
#define CSTOCS_GET_CHUNK_BLOCKS (PROTO_BASE+250)
/// chunkid:64 chunkversion:32

// 0x00FB
#define CSTOCS_GET_CHUNK_BLOCKS_STATUS (PROTO_BASE+251)
/// chunkid:64 chunkversion:32 blocks:16 status:8

//ANY <-> CHUNKSERVER

// 0x012C
#define ANTOCS_CHUNK_CHECKSUM (PROTO_BASE+300)
/// chunkid:64 chunkversion:32

// 0x012D
#define CSTOAN_CHUNK_CHECKSUM (PROTO_BASE+301)
/// chunkid:64 chunkversion:32 checksum:32
/// chunkid:64 chunkversion:32 status:8

// 0x012E
#define ANTOCS_CHUNK_CHECKSUM_TAB (PROTO_BASE+302)
/// chunkid:64 version:32

// 0x012F
#define CSTOAN_CHUNK_CHECKSUM_TAB (PROTO_BASE+303)
/// length==13 chunkid:64 chunkversion:32 status:8
/// length==12+MFSBLOCKSINCHUNK*4 chunkid:64 chunkversion:32 checksums:(1024 * [checksum:32])

// CLIENT <-> MASTER

// old attr record:
//   type:8 flags:8 mode:16 uid:32 gid:32 atime:32 mtime:32 ctime:32 length:64
//   total: 32B (1+1+2+4+4+4+4+4+8)
//
//   flags: ---DGGGG
//             |\--/
//             |  \------ goal
//             \--------- delete imediatelly

// new attr record:
//   type:8 mode:16 uid:32 gid:32 atime:32 mtime:32 ctime:32 nlink:32 length:64
//   total: 35B
//
//   mode: FFFFMMMMMMMMMMMM
//         \--/\----------/
//           \       \------- mode
//            \-------------- flags
//
//   in case of BLOCKDEV and CHARDEV instead of 'length:64' on the end there is 'mojor:16 minor:16 empty:32'

// NAME type:
// (size:8 data:STRING[size])

#define FUSE_REGISTER_BLOB_NOACL       "kFh9mdZsR84l5e675v8bi54VfXaXSYozaU3DSz9AsLLtOtKipzb9aQNkxeOISx64"
// CLTOMA:
//  clientid:32 [ version:32 ]
// MATOCL:
//  clientid:32
//  status:8

#define FUSE_REGISTER_BLOB_TOOLS_NOACL "kFh9mdZsR84l5e675v8bi54VfXaXSYozaU3DSz9AsLLtOtKipzb9aQNkxeOISx63"
// CLTOMA:
//  -
// MATOCL:
//  status:8

#define FUSE_REGISTER_BLOB_ACL         "DjI1GAQDULI5d2YjA26ypc3ovkhjvhciTQVx3CS4nYgtBoUcsljiVpsErJENHaw0"

#define REGISTER_GETRANDOM 1
// rcode==1: generate random blob
// CLTOMA:
//  rcode:8
// MATOCL:
//  randomblob:32B

#define REGISTER_NEWSESSION 2
// rcode==2: first register
// CLTOMA:
//  rcode:8 version:32 ileng:32 info:ilengB pleng:32 path:plengB [ passcode:16B ]
// MATOCL:
//  version:32 sessionid:32 sesflags:8 rootuid:32 rootgid:32 mapalluid:32 mapallgid:32
//  status:8

#define REGISTER_RECONNECT 3
// rcode==3: mount reconnect
// CLTOMA:
//  rcode:8 sessionid:32 version:32
// MATOCL:
//  status:8

#define REGISTER_TOOLS 4
// rcode==4: tools connect
// CLTOMA:
//  rcode:8 sessionid:32 version:32
// MATOCL:
//  status:8

#define REGISTER_NEWMETASESSION 5
// rcode==5: first register
// CLTOMA:
//  rcode:8 version:32 ileng:32 info:ilengB [ passcode:16B ]
// MATOCL:
//  version:32 sessionid:32 sesflags:8
//  status:8

#define REGISTER_CLOSESESSION 6
// rcode==6: close session
// CLTOMA:
//  rcode:8 sessionid:32
// MATOCL: -- no answer --

// 0x0190
#define CLTOMA_FUSE_REGISTER (PROTO_BASE+400)
/// blob:STRING[64] data:(depends on blob - see blob descriptions above)

// 0x0191
#define MATOCL_FUSE_REGISTER (PROTO_BASE+401)
/// status:8
// ----- old tools -----
/// sessionid:32
// ----- GETRANDOM -----
/// data:BYTES[32]
// ----- non-meta -----
// since 1.6.26
/// vershex:32 sessionid:32 sesflags:8 rootuid:32 rootgid:32 mapalluid:32 mapallgid:32 mingoal:8 maxgoal:8 mintrashtime:32 maxtrashtime:32
// since 1.6.21
/// vershex:32 sessionid:32 sesflags:8 rootuid:32 rootgid:32 mapalluid:32 mapallgid:32
// since 1.6.01
///            sessionid:32 sesflags:8 rootuid:32 rootgid:32 mapalluid:32 mapallgid:32
// older
///            sessionid:32 sesflags:8 rootuid:32 rootgid:32
// ----- meta -----
// since 1.6.26
/// vershex:32 sessionid:32 sesflags:8 mingoal:8 maxgoal:8 mintrashtime:32 maxtrashtime:32
// since 1.6.21
/// vershex:32 sessionid:32 sesflags:8
// older
///            sessionid:32 sesflags:8

// 0x0192
#define CLTOMA_FUSE_STATFS (PROTO_BASE+402)
// msgid:32 -

// 0x0193
#define MATOCL_FUSE_STATFS (PROTO_BASE+403)
/// msgid:32 totalspace:64 availspace:64 trashspace:64 reservedspace:64 inodecount:32

// 0x0194
#define CLTOMA_FUSE_ACCESS (PROTO_BASE+404)
/// msgid:32 inode:32 uid:32 gid:32 modemask:8

// 0x0195
#define MATOCL_FUSE_ACCESS (PROTO_BASE+405)
/// msgid:32 status:8

// 0x0196
#define CLTOMA_FUSE_LOOKUP (PROTO_BASE+406)
/// msgid:32 inode:32 name:NAME uid:32 gid:32

// 0x0197
#define MATOCL_FUSE_LOOKUP (PROTO_BASE+407)
/// msgid:32 status:8
/// msgid:32 inode:32 attr:35B

// 0x0198
#define CLTOMA_FUSE_GETATTR (PROTO_BASE+408)
/// msgid:32 inode:32
/// msgid:32 inode:32 uid:32 gid:32

// 0x0199
#define MATOCL_FUSE_GETATTR (PROTO_BASE+409)
/// msgid:32 status:8
/// msgid:32 attr:35B

// 0x019A
#define CLTOMA_FUSE_SETATTR (PROTO_BASE+410)
// msgid:32 inode:32 uid:32 gid:32 setmask:8 attr:32B   - compatibility with very old version
// msgid:32 inode:32 uid:32 gid:32 setmask:16 attr:32B  - compatibility with old version
// msgid:32 inode:32 uid:32 gid:32 setmask:8 attrmode:16 attruid:32 attrgid:32 attratime:32 attrmtime:32 - compatibility with versions < 1.6.25
// msgid:32 inode:32 uid:32 gid:32 setmask:8 attrmode:16 attruid:32 attrgid:32 attratime:32 attrmtime:32 sugidclearmode:8

// 0x019B
#define MATOCL_FUSE_SETATTR (PROTO_BASE+411)
/// msgid:32 status:8
/// msgid:32 attr:35B

// 0x019C
#define CLTOMA_FUSE_READLINK (PROTO_BASE+412)
/// msgid:32 inode:32

// 0x019D
#define MATOCL_FUSE_READLINK (PROTO_BASE+413)
/// msgid:32 status:8
/// msgid:32 path:STDSTRING

// 0x019E
#define CLTOMA_FUSE_SYMLINK (PROTO_BASE+414)
/// msgid:32 inode:32 name:NAME path:STDSTRING uid:32 gid:32

// 0x019F
#define MATOCL_FUSE_SYMLINK (PROTO_BASE+415)
/// msgid:32 status:8
/// msgid:32 inode:32 attr:35B

// 0x01A0
#define CLTOMA_FUSE_MKNOD (PROTO_BASE+416)
/// msgid:32 inode:32 name:NAME nodetype:8 mode:16 uid:32 gid:32 rdev:32

// 0x0588
#define LIZ_CLTOMA_FUSE_MKNOD (1000U + 416U)
/// msgid:32 inode:32 name:NAME nodetype:8 mode:16 umask:16 uid:32 gid:32 rdev:32

// 0x01A1
#define MATOCL_FUSE_MKNOD (PROTO_BASE+417)
/// msgid:32 status:8
/// msgid:32 inode:32 attr:35B

// 0x0589
#define LIZ_MATOCL_FUSE_MKNOD (1000U + 417U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 inode:32 attr:35B

// 0x01A2
#define CLTOMA_FUSE_MKDIR (PROTO_BASE+418)
/// msgid:32 inode:32 name:NAME mode:16 uid:32 gid:32 copysgid:8
/// msgid:32 inode:32 name:NAME mode:16 uid:32 gid:32 // version < 1.6.25

// 0x058A
#define LIZ_CLTOMA_FUSE_MKDIR (1000U + 418U)
/// msgid:32 inode:32 name:NAME mode:16 umask:16 uid:32 gid:32 copysgid:8

// 0x01A3
#define MATOCL_FUSE_MKDIR (PROTO_BASE+419)
/// msgid:32 status:8
/// msgid:32 inode:32 attr:35B

// 0x058B
#define LIZ_MATOCL_FUSE_MKDIR (1000U + 419U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 inode:32 attr:35B

// 0x01A4
#define CLTOMA_FUSE_UNLINK (PROTO_BASE+420)
/// msgid:32 inode:32 name:NAME uid:32 gid:32

// 0x01A5
#define MATOCL_FUSE_UNLINK (PROTO_BASE+421)
/// msgid:32 status:8

// 0x01A6
#define CLTOMA_FUSE_RMDIR (PROTO_BASE+422)
/// msgid:32 inode:32 name:NAME uid:32 gid:32

// 0x01A7
#define MATOCL_FUSE_RMDIR (PROTO_BASE+423)
/// msgid:32 status:8

// 0x01A8
#define CLTOMA_FUSE_RENAME (PROTO_BASE+424)
/// msgid:32 inode_src:32 name_src:NAME inode_dst:32 name_dst:NAME uid:32 gid:32

// 0x01A9
#define MATOCL_FUSE_RENAME (PROTO_BASE+425)
/// msgid:32 status:8
// since 1.6.21 (after successful rename):
/// msgid:32 inode:32 attr:35B

// 0x01AA
#define CLTOMA_FUSE_LINK (PROTO_BASE+426)
/// msgid:32 inode:32 inode_dst:32 name_dst:NAME uid:32 gid:32

// 0x01AB
#define MATOCL_FUSE_LINK (PROTO_BASE+427)
/// msgid:32 status:8
/// msgid:32 inode:32 attr:35B

// 0x01AC
#define CLTOMA_FUSE_GETDIR (PROTO_BASE+428)
/// msgid:32 inode:32 uid:32 gid:32 // old version (works like new version with flags==0)
/// msgid:32 inode:32 uid:32 gid:32 flags:8

// 0x01AD
#define MATOCL_FUSE_GETDIR (PROTO_BASE+429)
/// msgid:32 status:8
/// msgid:32 data:(N * [name:NAME inode:32 type:8]) // when GETDIR_FLAG_WITHATTR in flags is not set
/// msgid:32 data:(N * [name:NAME inode:32 attr:35B]) // when GETDIR_FLAG_WITHATTR in flags is set


// 0x01AE
#define CLTOMA_FUSE_OPEN (PROTO_BASE+430)
/// msgid:32 inode:32 uid:32 gid:32 flags:8

// 0x01AF
#define MATOCL_FUSE_OPEN (PROTO_BASE+431)
/// msgid:32 status:8
// since 1.6.9 if no error:
/// msgid:32 attr:35B

// 0x01B0
#define CLTOMA_FUSE_READ_CHUNK (PROTO_BASE+432)
/// msgid:32 inode:32 chunkindex:32

// 0x01B1
#define MATOCL_FUSE_READ_CHUNK (PROTO_BASE+433)
/// msgid:32 status:8
/// msgid:32 filelength:64 chunkid:64 chunkversion:32 locations:(N * [ip:32 port:16])
// msgid:32 length:64 srcs:8 srcs*[chunkid:64 version:32 ip:32 port:16] - not implemented

// 0x01B2
#define CLTOMA_FUSE_WRITE_CHUNK (PROTO_BASE+434) /* it creates, duplicates or sets new version of chunk if necessary */
/// msgid:32 inode:32 chunkindex:32

// 0x01B3
#define MATOCL_FUSE_WRITE_CHUNK (PROTO_BASE+435)
/// msgid:32 status:8
/// msgid:32 filelength:64 chunkid:64 chunkversion:32 locations:(N * [ip:32 port:16])

// 0x01B4
#define CLTOMA_FUSE_WRITE_CHUNK_END (PROTO_BASE+436)
/// msgid:32 chunkid:64 inode:32 filelength:64

// 0x01B5
#define MATOCL_FUSE_WRITE_CHUNK_END (PROTO_BASE+437)
/// msgid:32 status:8

// 0x01B6
#define CLTOMA_FUSE_APPEND (PROTO_BASE+438)
// msgid:32 inode:32 srcinode:32 uid:32 gid:32 - append to existing element

// 0x01B7
#define MATOCL_FUSE_APPEND (PROTO_BASE+439)
// msgid:32 status:8

// 0x01B8
#define CLTOMA_FUSE_CHECK (PROTO_BASE+440)
// msgid:32 inode:32

// 0x01B9
#define MATOCL_FUSE_CHECK (PROTO_BASE+441)
/// msgid:32 status:8
// up to version 1.6.22:
//      msgid:32 N*[ copies:8 chunks:16 ]
// since version 1.6.23:
///     msgid:32 counters:(CHUNK_MATRIX_SIZE * [chunks:32]) // 0 copies, 1 copy, ..., 10+ copies

// 0x01BA
#define CLTOMA_FUSE_GETTRASHTIME (PROTO_BASE+442)
/// msgid:32 inode:32 gmode:8

// 0x01BB
#define MATOCL_FUSE_GETTRASHTIME (PROTO_BASE+443)
/// msgid:32 status:8
/// msgid:32 tdirs:32 tfiles:32 data:(tdirs * [trashtime:32 dirs:32] tfiles * [trashtime:32 files:32])


// 0x01BC
#define CLTOMA_FUSE_SETTRASHTIME (PROTO_BASE+444)
/// msgid:32 inode:32 uid:32 trashtime:32 smode:8

// 0x01BD
#define MATOCL_FUSE_SETTRASHTIME (PROTO_BASE+445)
/// msgid:32 status:8
/// msgid:32 changed:32 notchanged:32 notpermitted:32


// 0x01BE
#define CLTOMA_FUSE_GETGOAL (PROTO_BASE+446)
/// msgid:32 inode:32 gmode:8

// 0x01BF
#define MATOCL_FUSE_GETGOAL (PROTO_BASE+447)
/// msgid:32 status:8
/// msgid:32 gdirs:8 gfiles:8 data:(gdirs * [goal:8 dirs:32] gfiles * [goal:8 files:32])

// 0x05A6
#define LIZ_CLTOMA_FUSE_GETGOAL (1000U + 446U)
/// msgid:32 inode:32 gmode:8

// 0x05A7
#define LIZ_MATOCL_FUSE_GETGOAL (1000U + 447U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 data:(std::vector<FuseGetGoalStats>)

// 0x01C0
#define CLTOMA_FUSE_SETGOAL (PROTO_BASE+448)
/// msgid:32 inode:32 uid:32 goal:8 smode:8

// 0x01C1
#define MATOCL_FUSE_SETGOAL (PROTO_BASE+449)
/// msgid:32 status:8
/// msgid:32 changed:32 notchanged:32 notpermitted:32

// 0x05A8
#define LIZ_CLTOMA_FUSE_SETGOAL (1000U + 448U)
/// msgid:32 inode:32 uid:32 goalname:STDSTRING smode:8

// 0x05A9
#define LIZ_MATOCL_FUSE_SETGOAL (1000U + 449U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 changed:32 notchanged:32 notpermitted:32

// 0x01C2
#define CLTOMA_FUSE_GETTRASH (PROTO_BASE+450)
/// msgid:32

// 0x01C3
#define MATOCL_FUSE_GETTRASH (PROTO_BASE+451)
/// length==5 msgid:32 status:8
/// length!=5 msgid:32 data:(N * [name:NAME inode:32])

// 0x01C4
#define CLTOMA_FUSE_GETDETACHEDATTR (PROTO_BASE+452)
/// msgid:32 inode:32 dtype:8

// 0x01C5
#define MATOCL_FUSE_GETDETACHEDATTR (PROTO_BASE+453)
/// msgid:32 status:8
/// msgid:32 attr:35B

// 0x01C6
#define CLTOMA_FUSE_GETTRASHPATH (PROTO_BASE+454)
/// msgid:32 inode:32

// 0x01C7
#define MATOCL_FUSE_GETTRASHPATH (PROTO_BASE+455)
/// msgid:32 status:8
/// msgid:32 path:STDSTRING

// 0x01C8
#define CLTOMA_FUSE_SETTRASHPATH (PROTO_BASE+456)
/// msgid:32 inode:32 path:STDSTRING

// 0x01C9
#define MATOCL_FUSE_SETTRASHPATH (PROTO_BASE+457)
/// msgid:32 status:8

// 0x01CA
#define CLTOMA_FUSE_UNDEL (PROTO_BASE+458)
/// msgid:32 inode:32

// 0x01CB
#define MATOCL_FUSE_UNDEL (PROTO_BASE+459)
/// msgid:32 status:8

// 0x01CC
#define CLTOMA_FUSE_PURGE (PROTO_BASE+460)
/// msgid:32 inode:32

// 0x01CD
#define MATOCL_FUSE_PURGE (PROTO_BASE+461)
/// msgid:32 status:8

// 0x01CE
#define CLTOMA_FUSE_GETDIRSTATS (PROTO_BASE+462)
/// msgid:32 inode:32

// 0x01CF
#define MATOCL_FUSE_GETDIRSTATS (PROTO_BASE+463)
// msgid:32 status:8
// msgid:32 inodes:32 dirs:32 files:32 ugfiles:32 mfiles:32 chunks:32 ugchunks:32 mchunks:32 length:64 size:64 gsize:64

// 0x01D0
#define CLTOMA_FUSE_TRUNCATE (PROTO_BASE+464)
// msgid:32 inode:32 [opened:8] uid:32 gid:32 opened:8 length:64

// 0x01D1
#define MATOCL_FUSE_TRUNCATE (PROTO_BASE+465)
/// msgid:32 status:8
/// msgid:32 attr:35B

// 0x01D2
#define CLTOMA_FUSE_REPAIR (PROTO_BASE+466)
/// msgid:32 inode:32 uid:32 gid:32

// 0x01D3
#define MATOCL_FUSE_REPAIR (PROTO_BASE+467)
/// msgid:32 status:8
/// msgid:32 notchanged:32 erased:32 repaired:32

// 0x01D4
#define CLTOMA_FUSE_SNAPSHOT (PROTO_BASE+468)
/// msgid:32 inode:32 inode_dst:32 name_dst:NAME uid:32 gid:32 canoverwrite:8

// 0x01D5
#define MATOCL_FUSE_SNAPSHOT (PROTO_BASE+469)
/// msgid:32 status:8

// 0x01D6
#define CLTOMA_FUSE_GETRESERVED (PROTO_BASE+470)
/// msgid:32

// 0x01D7
#define MATOCL_FUSE_GETRESERVED (PROTO_BASE+471)
/// length==5 msgid:32 status:8
/// length!=5 msgid:32 data:(N * [name:NAME inode:32])

// 0x01D8
#define CLTOMA_FUSE_GETEATTR (PROTO_BASE+472)
/// msgid:32 inode:32 gmode:8

// 0x01D9
#define MATOCL_FUSE_GETEATTR (PROTO_BASE+473)
/// msgid:32 status:8
/// msgid:32 eattrdirs:8 eattrfiles:8 data:(eattrdirs * [eattr:8 dirs:32] eattrfiles * [eattr:8 files:32])

// 0x01DA
#define CLTOMA_FUSE_SETEATTR (PROTO_BASE+474)
/// msgid:32 inode:32 uid:32 eattr:8 smode:8

// 0x01DB
#define MATOCL_FUSE_SETEATTR (PROTO_BASE+475)
/// msgid:32 status:8
/// msgid:32 changed:32 notchanged:32 notpermitted:32

// 0x01DE
#define CLTOMA_FUSE_GETXATTR (PROTO_BASE+478)
/// msgid:32 inode:32 opened:8 uid:32 gid:32 name:STRING8 xattrgmode:8
//   empty name = list names
//   xattrgmode:
//    0 - get data
//    1 - get length only

// 0x01DF
#define MATOCL_FUSE_GETXATTR (PROTO_BASE+479)
/// length==5 msgid:32 status:8
/// length==8 msgid:32 vleng:32
/// length>8  msgid:32 value:STRING32

// 0x01E0
#define CLTOMA_FUSE_SETXATTR (PROTO_BASE+480)
/// msgid:32 inode:32 uid:32 gid:32 name:STRING8 value:STRING32 xattrsmode:8
//   xattrsmode:
//    0 - create or replace
//    1 - create only
//    2 - replace only
//    3 - remove

// 0x01E1
#define MATOCL_FUSE_SETXATTR (PROTO_BASE+481)
/// msgid:32 status:8

//0x01E2
#define LIZ_CLTOMA_CHUNK_INFO (1000U + 482U)
/// msgid:32 inode:32 chunkindex:32

//0x01E3
#define LIZ_MATOCL_CHUNK_INFO (1000U + 483U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 filelength:64 chunkid:64 chunkversion:32 locations:(N * [ip:32 port:16 label:MediaLabel reserved:8])

// Abandoned sub-project - directory entries cached on client side
// directory removed from cache
// 0x01EA
// #define CLTOMA_FUSE_DIR_REMOVED (PROTO_BASE+490)
// msgid:32 N*[ inode:32 ]

// attributes of inode have changed
// 0x01EB
// #define MATOCL_FUSE_NOTIFY_ATTR (PROTO_BASE+491)
// msgid:32 N*[ inode:32 attr:35B ]

// new entry has been added
// 0x01EC
// #define MATOCL_FUSE_NOTIFY_LINK (PROTO_BASE+492)
// msgid:32 timestamp:32 N*[ parent:32 name:NAME inode:32 attr:35B ]

// entry has been deleted
// 0x01ED
// #define MATOCL_FUSE_NOTIFY_UNLINK (PROTO_BASE+493)
// msgid:32 timestamp:32 N*[ parent:32 name:NAME ]

// whole directory needs to be removed
// 0x01EE
// #define MATOCL_FUSE_NOTIFY_REMOVE (PROTO_BASE+494)
// msgid:32 N*[ inode:32 ]

// parent inode has changed
// 0x01EF
// #define MATOCL_FUSE_NOTIFY_PARENT (PROTO_BASE+495)
// msgid:32 N*[ inode:32 parent:32 ]

// last notification
// 0x01F0
// #define MATOCL_FUSE_NOTIFY_END (PROTO_BASE+496)
// msgid:32

// special - reserved (opened) inodes - keep opened files.
// 0x01F3
#define CLTOMA_FUSE_RESERVED_INODES (PROTO_BASE+499)
/// inodes:(N * [inode:32])

// MASTER STATS (stats - unregistered)

// 0x001F4
#define CLTOMA_CSERV_LIST (PROTO_BASE+500)
/// -

// 0x001F5
#define MATOCL_CSERV_LIST (PROTO_BASE+501)
//      N*[ip:32 port:16 used:64 total:64 chunks:32 tdused:64 tdtotal:64 tdchunks:32 errorcount:32 ]
// since version 1.5.13:
//      N*[version:32 ip:32 port:16 used:64 total:64 chunks:32 tdused:64 tdtotal:64 tdchunks:32 errorcount:32]

// 0x001F6
#define CLTOCS_HDD_LIST_V1 (PROTO_BASE+502)
/// -

// 0x001F7
#define CSTOCL_HDD_LIST_V1 (PROTO_BASE+503)
// N*[ path:NAME flags:8 errchunkid:64 errtime:32 used:64 total:64 chunkscount:32 ]

// 0x001F8
#define CLTOAN_CHART (PROTO_BASE+504)
/// chartid:32

// 0x001F9
#define ANTOCL_CHART (PROTO_BASE+505)
/// chart:(GIF)

// 0x001FA
#define CLTOAN_CHART_DATA (PROTO_BASE+506)
/// chartid:32

// 0x001FB
#define ANTOCL_CHART_DATA (PROTO_BASE+507)
/// time:32 data:(N * [entry:64])

// 0x001FC
#define CLTOMA_SESSION_LIST (PROTO_BASE+508)
/// -

// 0x001FD
#define MATOCL_SESSION_LIST (PROTO_BASE+509)
/// data:(N * [ip:32 vershex:32])

// 0x001FE
#define CLTOMA_INFO (PROTO_BASE+510)
/// -

// 0x001FF
#define MATOCL_INFO (PROTO_BASE+511)
//      totalspace:64 availspace:64 trashspace:64 trashnodes:32 reservedspace:64 reservednodes:32 allnodes:32 dirnodes:32 filenodes:32 chunks:32 tdchunks:32
// since version 1.5.13:
//      version:32 totalspace:64 availspace:64 trashspace:64 trashnodes:32 reservedspace:64 reservednodes:32 allnodes:32 dirnodes:32 filenodes:32 chunks:32 chunkcopies:32 tdcopies:32

// 0x00200
#define CLTOMA_FSTEST_INFO (PROTO_BASE+512)
/// -

// 0x00201
#define MATOCL_FSTEST_INFO (PROTO_BASE+513)
//      loopstart:32 loopend:32 files:32 ugfiles:32 mfiles:32 chunks:32 ugchunks:32 mchunks:32 msgleng:32 msgleng*[ char:8]
// since version 1.5.13
//      loopstart:32 loopend:32 files:32 ugfiles:32 mfiles:32 msgleng:32 msgleng*[ char:8]

// 0x00202
#define CLTOMA_CHUNKSTEST_INFO (PROTO_BASE+514)
/// -

// 0x00203
#define MATOCL_CHUNKSTEST_INFO (PROTO_BASE+515)
// loopstart:32 loopend:32 del_invalid:32 nodel_invalid:32 del_unused:32 nodel_unused:32 del_diskclean:32 nodel_diskclean:32 del_overgoal:32 nodel_overgoal:32 copy_undergoal:32 nocopy_undergoal:32 copy_rebalance:32

// 0x00204
#define CLTOMA_CHUNKS_MATRIX (PROTO_BASE+516)
/// matrixid:8

// 0x00205
#define MATOCL_CHUNKS_MATRIX (PROTO_BASE+517)
/// counters:(CHUNK_MATRIX_SIZE * CHUNK_MATRIX_SIZE * [chunks:32])
// 11x11 matrix of chunks counters (goal x validcopies), 10 means 10 or more

// 0x00208
#define CLTOMA_EXPORTS_INFO (PROTO_BASE+520)
/// -

// 0x00209
#define MATOCL_EXPORTS_INFO (PROTO_BASE+521)
// N * [ fromip:32 toip:32 pleng:32 path:plengB extraflags:8 sesflags:8 rootuid:32 rootgid:32 ]

// 0x0020A
#define CLTOMA_MLOG_LIST (PROTO_BASE+522)
/// -

// 0x0020B
#define MATOCL_MLOG_LIST (PROTO_BASE+523)
// N * [ version:32 ip:32 ]

// 0x05F2
#define LIZ_CLTOMA_METADATASERVERS_LIST (1000U + 522U)
/// -

// 0x05F3
#define LIZ_MATOCL_METADATASERVERS_LIST (1000U + 523U)
// masterversion:32 data:(N * [ ip:32 hostname:STDSTRING version:32])

// 0x0020C
#define CLTOMA_CSSERV_REMOVESERV (PROTO_BASE+524)
/// ip:32 port:16

// 0x0020D
#define MATOCL_CSSERV_REMOVESERV (PROTO_BASE+525)
/// -

// 0x05F6
#define LIZ_CLTOMA_CHUNKS_HEALTH (1000U + 526U)
/// regularonly:8

// 0x05F7
#define LIZ_MATOCL_CHUNKS_HEALTH (1000U + 527U)
/// regularonly:8 data:(ChunksAvailabilityState ChunksReplicationState)

// 0x05F8
#define LIZ_MATOCL_IOLIMITS_CONFIG (1000U + 528U)
/// cfgversion:32 period:32 subsystem:STDSTRING groups:(vector<STDSTRING>)

// 0x05F9
#define LIZ_CLTOMA_IOLIMIT (1000U + 529U)
/// msgid:32 cfgversion:32 group:STDSTRING bytes:64

// 0x05FA
#define LIZ_MATOCL_IOLIMIT (1000U + 530U)
/// msgid:32 cfgversion:32 group:STDSTRING bytes:64

// 0x05FB
#define LIZ_CLTOMA_FUSE_SET_ACL (1000U + 531U)
/// msgid:32 inode:32 uid:32 gid:32 acltype:8 mode:16 isextended:8 extendedacl:(isextended ? ExtendedAcl : ---)

// 0x05FC
#define LIZ_MATOCL_FUSE_SET_ACL (1000U + 532U)
/// msgid:32 status:8

// 0x05FD
#define LIZ_CLTOMA_FUSE_GET_ACL (1000U + 533U)
/// msgid:32 inode:32 uid:32 gid:32 acltype:8

// 0x05FE
#define LIZ_MATOCL_FUSE_GET_ACL (1000U + 534U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 mode:16 isextended:8 extendedacl:(isextended ? ExtendedAcl : ---)

// 0x05FF
#define LIZ_CLTOMA_FUSE_DELETE_ACL (1000U + 535U)
/// msgid:32 inode:32 uid:32 gid:32 acltype:8

// 0x0600
#define LIZ_MATOCL_FUSE_DELETE_ACL (1000U + 536U)
/// msgid:32 status:8

// 0x0601
#define LIZ_CLTOMA_FUSE_SET_QUOTA (1000U + 537U)
/// msgid:32 uid:32 gid:32 limits:(vector<QuotaEntryKey, limit:64>)

// 0x0602
#define LIZ_MATOCL_FUSE_SET_QUOTA (1000U + 538U)
/// msgid:32 status:8

// 0x0603
#define LIZ_CLTOMA_FUSE_DELETE_QUOTA (1000U + 539U)
/// msgid:32 uid:32 gid:32 limits:(vector<QuotaEntryKey>)

// 0x0604
#define LIZ_MATOCL_FUSE_DELETE_QUOTA (1000U + 540U)
/// msgid:32 status:8

// 0x0605
#define LIZ_CLTOMA_FUSE_GET_QUOTA (1000U + 541U)
// version==0 - all limits; version==1 - limits for passed users and/or groups
/// version==0 msgid:32 uid:32 gid:32
/// version==1 msgid:32 uid:32 gid:32 owners:(vector<QuotaOwner>)

// 0x0606
#define LIZ_MATOCL_FUSE_GET_QUOTA (1000U + 542U)
/// version==0 msgid:32 status:8
/// version==1 msgid:32 limits:(vector<QuotaOwnerAndLimits>)

// 0x0607
#define LIZ_CLTOMA_IOLIMITS_STATUS (1000U + 543U)
/// msgid:32

// 0x0608
#define LIZ_MATOCL_IOLIMITS_STATUS (1000U + 544U)
/// msgid:32 cfgversion:32 period:32 accumulation:32 subsystem:STDSTRING groupslimits:(vector<STDSTRING, uint64_t>)

// 0x0609
#define LIZ_CLTOMA_METADATASERVER_STATUS (1000U + 545U)
/// msgid:32

// 0x060A
#define LIZ_MATOCL_METADATASERVER_STATUS (1000U + 546U)
/// msgid:32 serverstatus:8 metadataversion:64

// 0x060D
#define LIZ_CLTOMA_LIST_GOALS (1000U + 547U)
/// dummy:8

// 0x060C
#define LIZ_MATOCL_LIST_GOALS (1000U + 548U)
/// goals:(vector<uint16_t, STDSTRING, STDSTRING>)

// 0x060D
#define LIZ_CLTOMA_CSERV_LIST (1000U + 549U)
/// dummy:8

// 0x060E
#define LIZ_MATOCL_CSERV_LIST (1000U + 550U)
/// chunkservers:(vector<ChunkserverListEntry>)

// 0x060F
#define LIZ_CLTOMA_HOSTNAME (1000U + 551U)
/// -

// 0x0610
#define LIZ_MATOCL_HOSTNAME (1000U + 552U)
/// hostname:STDSTRING

// 0x0611
#define LIZ_CLTOMA_ADMIN_REGISTER_CHALLENGE (1000U + 553U)
/// -

// 0x0612
#define LIZ_MATOCL_ADMIN_REGISTER_CHALLENGE (1000U + 554U)
/// challenge:BYTES[32]

// 0x0613
#define LIZ_CLTOMA_ADMIN_REGISTER_RESPONSE (1000U + 555U)
/// response:BYTES[16]

// 0x0614
#define LIZ_MATOCL_ADMIN_REGISTER_RESPONSE (1000U + 556U)
/// status:8

// 0x0615
#define LIZ_CLTOMA_ADMIN_BECOME_MASTER (1000U + 557U)
/// -

// 0x0616
#define LIZ_MATOCL_ADMIN_BECOME_MASTER (1000U + 558U)
/// status:8

// 0x0617
#define LIZ_CLTOMA_ADMIN_STOP_WITHOUT_METADATA_DUMP (1000U + 559U)
/// -

// 0x0618
#define LIZ_MATOCL_ADMIN_STOP_WITHOUT_METADATA_DUMP (1000U + 560U)
/// status:8

// 0x0619
#define LIZ_CLTOMA_ADMIN_RELOAD (1000U + 561U)
/// -

// 0x061A
#define LIZ_MATOCL_ADMIN_RELOAD (1000U + 562U)
/// status:8

// 0x061B
#define LIZ_CLTOMA_ADMIN_SAVE_METADATA (1000U + 563U)
/// asynchronous:8

// 0x061C
#define LIZ_MATOCL_ADMIN_SAVE_METADATA (1000U + 564U)
/// status:8

// 0x061D
#define LIZ_CLTOMA_ADMIN_RECALCULATE_METADATA_CHECKSUM (1000U + 565U)
/// asynchronous:8

// 0x061E
#define LIZ_MATOCL_ADMIN_RECALCULATE_METADATA_CHECKSUM (1000U + 566U)
/// status:8

// CHUNKSERVER STATS

// 0x0258
#define CLTOCS_HDD_LIST_V2 (PROTO_BASE+600)
/// -

// 0x0259
#define CSTOCL_HDD_LIST_V2 (PROTO_BASE+601)
// N*[ entrysize:16 path:NAME flags:8 errchunkid:64 errtime:32 used:64 total:64 chunkscount:32 bytesread:64 usecread:64 usecreadmax:64 byteswriten:64 usecwrite:64 usecwritemax:64]

// TAPESERVER <-> MASTER

// 0x06A4
#define LIZ_TSTOMA_REGISTER_TAPESERVER (1000U + 700U)
/// vershex:32

// 0x06A5
#define LIZ_MATOTS_REGISTER_TAPESERVER (1000U + 701U)
/// version==0 status:8
/// version==1 vershex:32

// 0x06A6
#define LIZ_TSTOMA_HAS_FILES (1000U + 702U)
/// tapecontents:(vector<inode:32,mtime:32,length:64>)

// 0x06A7
#define LIZ_TSTOMA_END_OF_FILES (1000U + 703U)
/// -
