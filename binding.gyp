{
  'targets': [{
    'target_name': 'pty-pair',
    'sources': [
      'src/pty_pair.cpp'
    ],
   	'include_dirs': [
      '<!(node -e "require(\'nan\')")'
    ],
   	'conditions': [
      ['OS=="linux"', {
        'cflags': [
          '-lutil',
          '-pthread',
          '-static'
        ],
      }],
    ],
   }]
}