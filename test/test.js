// test.js
const addon = require('./build/Debug/sharedmemory')

console.log('methods:', addon)
{
  const key = 'kkk'
  try {
    console.log('try to setMemory:')
    console.log(addon.setMemory(key, 2))
    const mem1 = addon.getMemory(key)
    console.log(mem1)
    const u8 = new Uint8Array(mem1)
    u8[0] = 1

    console.log(u8)
    // // // 重新获取
    console.log('重新获取：')
    const mem2 = addon.getMemory(key)
    // // console.log(mem2)
    console.log(new Uint8Array(mem2))
  }
  catch (error) {
    console.log(error)
  }
  finally {
    console.log('清除：')
    addon.removeMemory(key)
    addon.removeAll()
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
