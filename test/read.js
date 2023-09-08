// test.js
const addon = require('../build/Debug/sharedmemory')

const sleep = (time) => {
  return new Promise((resolve, reject) => {
    setTimeout(resolve, time)
  })
}
console.log('methods:', addon)
{
  const key = 'skyline_20_1694149932887'
  try {
    console.log('try to getMemory:')
    const mem1 = addon.getMemory(key)
    // console.log(mem1)
    const u8 = new Uint8Array(mem1)
    console.log(u8)
    u8[0] = 2

    // sleep(30000)
  }
  catch (error) {
    console.log(error)
  }
  finally {
    console.log('清除：')
    // addon.removeMemory(key)
    // addon.removeAll()
  }
}
// {
//   const len = 5
//   const buf = new ArrayBuffer(len);
//   const u8 = new Uint8Array(buf);
//   for (let i = 0; i < len; i++) {
//     u8[i] =  i + 1
//   }
//   console.log(addon.transfer(buf))
// }
// addon((msg) => {
//   console.log(msg);
// // Prints: 'hello world'
// });
