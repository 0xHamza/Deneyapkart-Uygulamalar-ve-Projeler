
import os
import urllib.parse

def generate_readme(root_dir):

    headers = []
    header_id = 0

    def process_directory(directory, indent_level=0):
        nonlocal readme_content
        nonlocal headers
        nonlocal header_id
        indent = '#' * (2 + indent_level)
        subdirectories = []
        files = []
        
        for item in os.listdir(directory):
            item_path = os.path.join(directory, item)
            if os.path.isdir(item_path):
                subdirectories.append(item)
                print("directory: ",item)
            elif item.endswith('.ino') or item.endswith(('.jpg', '.jpeg', '.png', '.pde','.exe')):
                files.append(item)
        
        if indent_level == 0:
            nm = os.path.basename(directory).replace("_", " ")
            readme_content += f"{indent} {nm}\n"

        if files:
            nm = os.path.basename(directory).replace("_", " ")

            header_id += 1
            header_str = f'- {header_id} <a href="#{header_id}">{nm}</a>' 
            headers.append(header_str)
            
            readme_content += f"{indent} {nm} <span id=\"{header_id}\"></span>\n"
            readme_content += "- Açıklama:\n"

            for file_name in files:
                file_path = os.path.relpath(os.path.join(directory, file_name), root_dir).replace("\\", "/")
                file_path = urllib.parse.quote(file_path)  # Boşlukları %20 ile değiştir

                if file_name.endswith('.ino'):
                    file_type = "Kod"
                elif file_name.endswith(('.jpg', '.jpeg', '.png')):
                    file_type = "Resim"
                else :
                    file_type = "Dosya"

                if file_type == "Resim":
                    readme_content += f"- {file_type}: [{file_name}]({file_path})\n"
                    readme_content += f'  <br><img src="{file_path}" alt="{file_name}" style="max-height: 300px;">\n'
                else:
                    readme_content += f"- {file_type}: [{file_name}]({file_path})\n"
            readme_content += "\n"

        for subdirectory in subdirectories:
            process_directory(os.path.join(directory, subdirectory), indent_level + 1)

    readme_content = "\n # Deneyap Kart Örnek Uygulamalar ve Kodlar Detaylı Liste\n\n"

    # README.md dosyasının başlığı, repo hakkında genel bilgiler içermeli

    readme_header = """

Deneyap Kart Projeler
========================

Bu repo, Deneyap Teknoloji Atölyeleri Nesnelerin İnterneti ve İleri Robotik dersleri sırasında Deneyap Geliştirme Kartı ile yapılmış örnek projelerin kodlarını ve bağlantı şemalarını içerir. Projelerin detaylarına ulaşmak için aşağıdaki listeden ilgili projenin adına tıklayabilirsiniz.

Kodlar Arduino ile Deneyap Kart üzerinde çalışacak şekilde hazırlanmıştır. Aynı zamanda ESP32 tabanlı ESP8266, NodeMCU gibi geliştirme kartları üzerinde de çalıştırılabilir.

Listede yer almayan projeleri eklemek için PR gönderebilirsiniz. Listede yer alan projelerin kodlarında karşılaştığınız hataları veya projelerin geliştirilmesi için önerilerinizi iletmek için issue açabilirsiniz.

Lisans ve Kullanım Hakkında:
---------------------------
Repodan ve kodlardan faydalanabilirsiniz. Projeleri kendi projelerinizde kullanabilirsiniz. Ancak projeleri paylaşırken repoya referans vermeniz gerekmektedir. Ticari kullanımlar için lütfen iletişime geçiniz.

Detaylı bilgi için [Deneyap Kart](https://deneyapkart.org/) web sitesini ziyaret edebilirsiniz. Projelerin nasıl yükleneceği ve çalıştırılacağı hakkında bilgi almak için [Deneyap Kart Kullanım Kılavuzu](https://deneyapkart.org/docs/deneyap-kart) sayfasını ziyaret edebilirsiniz. Deneyap Kart Geliştirme Kartının orijinal reposuna [buradan](link-to-original-repo) ulaşabilirsiniz.

İlgili görüş ve önerileriniz için:
-----------------------------------
Derleyen ve Repo Sahibi: [0xhamza](https://github.com/0xHamza)

## İçindekiler


\n
"""

    headers.append(readme_header)


    illegal_files = ['.vs','.git', '.vscode', 'LICENSE', 'generate_readme.py']


    for item in os.listdir(root_dir):
        
        #chech if item is in illegal_files
        if item in illegal_files:
            continue

        item_path = os.path.join(root_dir, item)
        if os.path.isdir(item_path):
            process_directory(item_path)
        else:
            continue  # Skip files in the root directory

    with open(os.path.join(root_dir, 'README.md'), 'w', encoding='utf-8') as readme_file:

        file_content = ""

        for header in headers:
            file_content += header + "\n"

        file_content += readme_content
        readme_file.write(file_content)

# Kendi projeler klasörünüzün yolunu buraya ekleyin
root_directory = "C:\\Users\\hamza\\Source\\Repos\\Deneyapkart-Uygulamalar-ve-Projeler"

generate_readme(root_directory)

print("README.md dosyası oluşturuldu.")
