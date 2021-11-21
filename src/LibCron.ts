import { resolve } from 'path';
import { LLVM } from 'smake';

export abstract class LibCron {
  static config(llvm: LLVM) {
    llvm.includedirs = [
      ...llvm.includedirs,
      resolve(__dirname, '..', 'include').replace(/\\/g, '/'),
    ];
  }
}
