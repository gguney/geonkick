### Changes from 2.1.0 to 2.1.1

#### Fixes

  - fix install of *.desktop file
  - fix finding Redkite `lib64` in `FindRedkite.cmake`
  - add loading WAVEX samples

### Changes from 2.0.2 to 2.1.0

#### Fixes

  - fix loading stereo samples

#### Improvements

  - better quality of tuning

### Changes from 2.0.1 to 2.0.2

#### Fixes

  - fix saving kit state for standalone


### Changes from 2.0.0 to 2.0.1

#### Fixes

  - fixed the crash when opening a directory as kit preset

#### Other

  - moved presets into doc/examples

### Changes from 1.10.0 to 2.0.0

#### Features:

  - VST3 plugin support for GNU/Linux
  - seed for noise generator to have different noise patterns
  - add copy/paste between percussions
  - add shortcut keys to navigate and change the kit list order

#### Improvements:

  - noise pattern does not change when synthesizer parameters are changed.
    Load/save preset will preserve the noise pattern too
  - keep the order of percussion when saving/opening state or preset
  - add new percussion only at the the end
  - when starting to edit a percussion name move cursor by default to the end
  - reduce unnecessary updates of the UI when changing parameters

#### Fixes:

   - the shortcuts and key 'k'
   - a bug regarding "grabbing" window manager keys
   - set "any" key
   - updating the name in the toolbar
   - not updating the current percussion envelopes when adding a new default
   - reset to default percussion
   - limiter leveler for plugin
   - related to loading the preset from the host list of states (for LV2)
   - debug level when debugging
   - ttl LV2 validation errors
   - fixed wrong linking to experimental version of filesystem for GCC version >= 8

### Changes from 1.9.2 to 1.10.0

#### Freatures

   - percussion kit - supports up the 16 percussions in the kit
   - multichannel support - supports up to 16 audio output channels
   - distortion drive envelope
   - distortion effect input limiter
   - play percussion button
   - for build system check if Redkite is installed
   - enabled back the shortcut "k" key for triggering sound
   - documentation
   - backward compatibility, i.e. will load older presets

#### Improvements

   - improved the checkbox for effects
   - resonance knob was reversed

#### Fixes

   - fixed skipping notes for some hosts when notes are in a raw
   - fixed the crash for file dialog when going	to top file system '/' directory
   - fixed the label of FM checkbox
