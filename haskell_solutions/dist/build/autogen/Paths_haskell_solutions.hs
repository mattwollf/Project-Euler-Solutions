module Paths_haskell_solutions (
    version,
    getBinDir, getLibDir, getDataDir, getLibexecDir,
    getDataFileName, getSysconfDir
  ) where

import qualified Control.Exception as Exception
import Data.Version (Version(..))
import System.Environment (getEnv)
import Prelude

catchIO :: IO a -> (Exception.IOException -> IO a) -> IO a
catchIO = Exception.catch

version :: Version
version = Version [0,1,0,0] []
bindir, libdir, datadir, libexecdir, sysconfdir :: FilePath

bindir     = "/home/mwolf/projects/pe_solutions/haskell_solutions/.cabal-sandbox/bin"
libdir     = "/home/mwolf/projects/pe_solutions/haskell_solutions/.cabal-sandbox/lib/x86_64-linux-ghc-7.10.2/haskell-solutions-0.1.0.0-70UoVQuMjvfANUG2la5gXI"
datadir    = "/home/mwolf/projects/pe_solutions/haskell_solutions/.cabal-sandbox/share/x86_64-linux-ghc-7.10.2/haskell-solutions-0.1.0.0"
libexecdir = "/home/mwolf/projects/pe_solutions/haskell_solutions/.cabal-sandbox/libexec"
sysconfdir = "/home/mwolf/projects/pe_solutions/haskell_solutions/.cabal-sandbox/etc"

getBinDir, getLibDir, getDataDir, getLibexecDir, getSysconfDir :: IO FilePath
getBinDir = catchIO (getEnv "haskell_solutions_bindir") (\_ -> return bindir)
getLibDir = catchIO (getEnv "haskell_solutions_libdir") (\_ -> return libdir)
getDataDir = catchIO (getEnv "haskell_solutions_datadir") (\_ -> return datadir)
getLibexecDir = catchIO (getEnv "haskell_solutions_libexecdir") (\_ -> return libexecdir)
getSysconfDir = catchIO (getEnv "haskell_solutions_sysconfdir") (\_ -> return sysconfdir)

getDataFileName :: FilePath -> IO FilePath
getDataFileName name = do
  dir <- getDataDir
  return (dir ++ "/" ++ name)
