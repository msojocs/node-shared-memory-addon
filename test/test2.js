const SharedMemory = require('./SharedMemory.js')
const NAME = 'DATA'
const SIZE = 1024

// create memory
// not implemented

// open memory
const sm = new SharedMemory(NAME, SIZE)

// write data to the specified address (write...(address,value))
console.log('test start')
console.log(sm.writeFloat(0, 12.1))
console.log('2')
sm.writeDouble(4, 23.2)
sm.writeInt8(12, -8)
sm.writeInt16(13, -16)
sm.writeInt32(15, -32)
sm.writeUInt8(19, 8)
sm.writeUInt16(20, 16)
sm.writeUInt32(22, 32)

// read data from the specified address (read...(address))
sm.readFloat(0) // return 12.1
sm.readDouble(4) // return 23.2
sm.readInt8(12) // return -8
sm.readInt16(13) // return -16
sm.readInt32(15) // return -32
sm.readUInt8(19) // return 8
sm.readUInt16(20) // return 16
sm.readUInt32(22) // return 32