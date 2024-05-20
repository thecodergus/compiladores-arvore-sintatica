# Projeto de exemplo para uso do GenICam com C
project('Aplicação', 'c')

# Inicia as flags de compilação como um vetor vazio
c_args = []

# Adiciona flags de compilação para o GCC e Clang
cc = meson.get_compiler('c')
if cc.get_id() == 'gcc' or cc.get_id() == 'clang'
 c_args += '-Wno-deprecated'
endif

# Importa as pastas de cabeçalho
inc = include_directories('include', '/usr/local/include')

# Local para importar as dependencias
flex_program = find_program('flex', required: true)
bison_program = find_program('bison', required: true)

if not flex_program.found()
  error('MESON_SKIP_TEST flex not found.')
endif

if not bison_program.found()
  error('MESON_SKIP_TEST bison not found.')
endif

lgen = generator(flex_program, 
                output: [
                  '@BASENAME@.c', 
                  '@BASENAME@.h'
                  ], 
                arguments: [ 
                  '--outfile=@OUTPUT0@', 
                  '--header-file=@OUTPUT1@', 
                  '@INPUT@'
                  ]
              )

pgen = generator(bison_program,
                 output: [
                          '@BASENAME@.tab.c', 
                          '@BASENAME@.tab.h'
                        ],
                 arguments: [ 
                              '-Wall',
                              '--output=@OUTPUT0@',
                              '--defines=@OUTPUT1@',
                              '@INPUT@' 
                            ]
                )



# Importa os arquivos de código fonte
app_src = files(
  'src/main.c',
  'src/arv.c',
  'src/atrib.c'
)

# Aplicação Central
executable('main',
   sources : [
    app_src,
    lgen.process('gramatica/expr.l'),
    pgen.process('gramatica/expr.y')
   ],
   include_directories : inc,
   dependencies: [

   ],
   install: true,
   c_args : c_args
 )