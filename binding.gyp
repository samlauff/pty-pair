{
  'targets': [{
    'target_name': 'pty-pair',
    'sources': [
      'src/pty_pair.cc'
    ],
   	'include_dirs': [
      '<!(node -e "require(\'nan\')")'
    ],
    'libraries': [
      '-lutil',
      '-pthread',
    ]
   }]
}