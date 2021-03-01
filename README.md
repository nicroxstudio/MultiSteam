# MultiBrainCloud

> Ejemplo de desarrollo multiplayer con lobby en unreal 4 , para la versión 4.24

Existen 2 carpetas dentro del directorio del proyecto **Multiplayer_BrainCloud**

1. **MultiBrainCloud**: Donde se encuentra el proyecto para Visual Studio y Unreal. En el se genearn los binarios y las modificaciones del proyecto.

2. **Empaquetado**: Donde Hubicaremos los proyectos empaquetados tanto de *cliente* como de *servidor*


## Repositorio Unreal Github para multiplayer

###  Pasos para su utiliación
1. Autorizar a epicgame para conectar con github
2. Entrar en el repositorio y clonarlo para nosotros
3. Seleccionar la rama de la 4.24 y descargar en zip
4. A ser posible cambiar la ruta de descargas de http a https ..... (documentar)
5. Ejecutar **setup.bat** (Recomendable desde *PowerSelf* con permisos de administrador , mejor Pegarlo en *PS C:\Ue4\UE424>* Es importante reducir el nombre del path)
6. Ejecutar **GenerateProjectFiles.bat**
7. Descargar NET framework 4.6.2
8. Descargar y ejecutar Visual Studio 2017 ( importante no 2019 )
9. Ejecutar **UE4.sln**
10. Seleccionar en el árbol del proyecto **EU4** botón derecho "*Establecer como proyecto de inicio*".

## Multiplayer y creación de servidor dedicado
####  Instalar servidor en instancia Amazon
> https://www.youtube.com/watch?v=QHB1H6eM-vc
#### Crear servidor dedicado
1. Crear instancia en Amazon de Windows Server
2.  Seguir las instruciones del "*Repositorio Unreal Github para multiplayer*"
3.  Copiar el archivo "*C:\Ue4\UE424\Engine\Source\UE4Server.Target.cs*" a la carperta "**source** de nuestro proyecto"
4. Renombrar el archivo y su contenido con el nombre del proyecto, como se describe en este [enlace](https://docs.unrealengine.com/en-US/InteractiveExperiences/Networking/HowTo/DedicatedServers/index.html). 
5. Cerramos El proyecto y en "*TestMultigame.uproject*" , **botón derecho > Switch Unreal Engine Version > version build ...**
6. Abrir proyecto "*Developer server > build*" y luego "Developer Editor > build".
7. Modificar proyecto para *Multiplayer como describe el video*.
